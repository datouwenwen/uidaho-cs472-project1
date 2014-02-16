/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Header file for a base class which represents an individual
 * potential solution. Can be derived for, say, a ranged individual.
 */

#ifndef _INDIVIDUAL_H_
#define _INDIVIDUAL_H_

#include <array>
#include <cstdlib>
#include <string>

#include "random_generator.hpp"
extern RandomGenerator rg;

namespace Parameters {
  typedef float parameter;
  typedef std::uniform_real_distribution<parameter> real_dist;
  typedef std::uniform_int_distribution<> int_dist;
  typedef std::normal_distribution<parameter> normal_dist;
}

using namespace Parameters;

class Individual {
private:
  parameter min;
  parameter max;
  static int const dimension = 30;
  typedef std::array <parameter, dimension> genome;
  genome solution;

public:
  Individual();
  Individual(const parameter n,
	     const parameter x,
	     real_dist range_dis);

  const virtual std::string represent() const;
  void mutate(parameter & value, const parameter value_i) const;

  // Individual acts like std::array solution iterator
  genome::iterator begin();
  genome::iterator end();
  genome::const_iterator begin() const;
  genome::const_iterator end() const;
  genome::size_type size() const;
};

#endif /* _INDIVIDUAL_H_ */
