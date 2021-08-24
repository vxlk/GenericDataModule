#include "ImmutableProperty.hpp"

#include <vector>
#include <functional>

// A State Property is an immutable "Property" who
// tracks its state changes internally.
//
// State changes can be regulated by Validator functions (predicates)
//
// History is tracked for every change, and a string reason may (should) be given
// for the update.
template <class T>
class StateProperty : public ImmutableProperty<T> {
public:

	struct State {
		const T val;
		const std::string reason;
	};

	using validator_t = std::function<bool(T)>;
	using state_history_t = std::vector<const State<T>>;

	// with T val = {} as a default param:
	// THIS REALLY SHOULD BE C++20!
	// need a check that default constructor exists!
	StateProperty(T val = {},
		std::string name = "",
		validator_t predicate = [](T t) { return true; })
		:
		m_name(std::forward<std::string>(name)),
		m_validator(std::forward<validator_t>(predicate))
	{
		m_dataType.emplace(val);
		m_stateHistory.emplace_back(val, "Initial State");
	}

	// Uses the same constructors as a Property
	~ChangeProperty = default;

	void update(T t, std::string reason = "No reason given") {
		if (m_validator(t)) {
			m_dataType.emplace(t);
			m_stateList.emplace_back(t, reason);
			m_stateIndex++;
		}
	}

	const State<T>& back() const {
		if (m_stateIndex == 0)
			return m_stateHistory[0];
		m_stateIndex--;
		return m_stateHistory.at(m_stateIndex);
	}

	const State<T>& forward() const {
		if (m_stateIndex == m_stateHistory.size() - 1)
			return m_stateHistory[m_stateIndex];
		m_stateIndex++;
		return m_stateHistory.at(m_stateIndex);
	}

	const state_history_t& history() const {
		return m_stateHistory;
	}

private:
	mutable state_history_t m_stateHistory {};
	mutable int m_stateIndex = 1;
	validator_t m_validator;
};