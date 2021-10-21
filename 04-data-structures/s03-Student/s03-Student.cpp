#include <iostream>
#include <Student.h>

Student::Student::Student(std::string const firstn, std::string const forn, std::string ib, unsigned short t, float ag)
    : firstname{std::move(firstn)}
    , forname{std::move(forn)}
    , index_book{std::move(ib)}
    , term{t}
    , average_grade{ag}
{}

auto Student::Student::to_string() const -> std::string
{
    auto out = std::ostringstream{};
    out << firstname << " " << forname << " (" << index_book << "), semestr" << term << ": " << average_grade;
    return out.str();
}

auto main() -> int{

    auto me = Student::Student{"Michał", "Koter", "s24569", 1, 3.567};
    std::cout << me.to_string() << "\n";
    return 0;
}
