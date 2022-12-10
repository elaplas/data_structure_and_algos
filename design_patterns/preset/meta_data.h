#ifndef CHALLENGE_META_DATA_H_
#define CHALLENGE_META_DATA_H_

#include <string>

namespace Task {

/**
 * Struct for time
 */
struct Time
{
  /// Year
  int year;
  /// Month
  int month;
  /// Day
  int day;
  /// Hour
  int hour;
  /// Minute
  int min;
  /// Second
  int sec;

  /**
   * Setter for time
   *
   * @param ye  year
   * @param mo  month
   * @param da  day
   * @param h   hour
   * @param mi  minute
   * @param se  second
   */
  void setTime(const int ye, const int mo, const int da,
               const int h, const int mi, const int se)
  {
    year = ye;
    month = mo;
    day = da;
    hour = h;
    min = mi;
    sec = se;
  }
};

/**
 * Struct for meta data
 */
struct MetaData
{
  /// Name
  std::string name;
  /// Description
  std::string description;
  /// Version
  std::string version;
  /// Time
  Time time;
};

}

#endif //CHALLENGE_META_DATA_H_
