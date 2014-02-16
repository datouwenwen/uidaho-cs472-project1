/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for abstract base algorithm class
 */

#include "algorithm.hpp"

Algorithm::Algorithm(const Problem & p) : problem(p) {
}

const Individual Algorithm::mutate(const Individual & subject) const {
  // basic mutation by delta distribution and chance
  Individual mutation = subject;
  int_dist percent(1, 100);
  real_dist delta_dist(-problem.delta * (std::abs(problem.domain_min) +
					 std::abs(problem.domain_max)) / 2,
		       problem.delta * (std::abs(problem.domain_min) +
					std::abs(problem.domain_max)) / 2);
  for (parameter & value : mutation)
    if (problem.chance || percent(rg.engine) < int(100 * problem.chance))
      mutation.mutate(value, value + delta_dist(rg.engine));
  return mutation;
}
