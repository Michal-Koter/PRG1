#ifndef Time_h
#define Time_h

#include <iostream>
#include <sstream>
#include <string>

namespace s24569 {

struct Time{
    int hour{};
    int minute{};
    int second{};

// time of day
    enum class Time_of_day {
        MORNING,
        AFTERNOON,
        EVENING,
        NIGHT
    };

// time- constructor
    Time() = default;
    explicit Time(int hh, int mm, int ss)
        : hour{hh}
        , minute{mm}
        , second{ss}
    {
        if (hh > 23 && hh < 0) {
            throw std::out_of_range{"hour value cannot exceed 23"};
        }
        if (mm > 59 && mm < 0) {
            throw std::out_of_range{"minute value cannot exceed 59"};
        }
        if (ss > 59 && ss < 0) {
            throw std::out_of_range{"second value cannot exceed 59"};
        }

    }

// time- functions
    auto to_string() const -> std::string;
    auto next_hour() -> void;
    auto next_minute() -> void;
    auto next_second() -> void;

// time of day- functions
    auto time_of_day() const -> Time_of_day;
    auto to_string(Time_of_day) -> std::string;

// arithmetic
    auto operator+ (Time const&) const -> Time;
    auto operator- (Time const&) const -> Time;
    auto operator< (Time const&) const -> bool;
    auto operator> (Time const&) const -> bool;
    auto operator== (Time const&) const -> bool;
    auto operator!= (Time const&) const -> bool;

// seconds to midnight
    auto count_seconds() const -> uint64_t;
    auto count_minutes() const -> uint64_t;
    auto time_to_midnight() const -> Time;
};

}
#endif