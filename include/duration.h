#ifndef DURATION_H
#define DURATION_H
#include <ostream>
  
/**
* @brief Represents a length of time in minutes and seconds.
*@invariant The stored total seconds (m_total_seconds) is never negative
*/
class Duration {
public:
  
/**
* @brief Construct a new Duration object.
* @param minutes The mintues component (default to 0)
* @param seconds The seconds component (defaults to 0).
*/
Duration(int minutes = 0, int seconds = 0);
 
/**
* @brief Get the total duration in seconds.
* @return int Total seconds.
*/
 int total_seconds() const;
 
 
/**
* @brief Add another duration to this one.
* @param other The other Duration instance to add.
* @return Duration a new Duration object.
*/
  Duration operator+(const Duration& other) const;

 
/**
* @brief Compare two durations for equality.
* @param other The other Duration to compare against.
* @return true If both durations have the exact same total seconds.
* @return false Otherwise.
*/  
  bool operator==(const Duration& other) const;



  private:
      int m_total_seconds;
  };
 
/**
* @brief Stream insertion operator to print a Duration in m:ss format.
* @param out The output stream.
* @param d The Duration object to print
* @return std::ostream& Reference to the output stream for chaining.
*/
 std::ostream& operator<<(std::ostream& out, const Duration& d);
 
#endif
