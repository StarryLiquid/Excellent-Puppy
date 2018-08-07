#include "Base.hpp"

using namespace ExcellentPuppy;

std::unordered_set<Base *>* const Base::getDependents() {
	return &_dependents;
}
std::unordered_set<Base *>* const Base::getDependentArrays() {
	return &_dependentArrays;
}

Base::Base() { }
Base::~Base() {
	for (auto dependent : _dependents) {
		delete(dependent);
	}
}
