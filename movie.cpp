#include "movie.h"

#include <cmath>
#include <functional>
#include <iostream>

using namespace std;

Movie::Movie(int stock, string director, string title, int releaseYear,
             Movie::MovieKind kind)
    : stock(stock), director(director), title(title), kind(kind),
      releaseYear(releaseYear) {

  ID = determineID();
  PRINT_ID = true; // If true, << also prints ID.
}

/**
 * Determines an ID for the movie.
 *
 * The first digit represents the movie's kind.
 * The next 3 digits are determined by the movie's title.
 * The last 2 digits are determined by the movie's release year.
 *
 * @return An int representing the Movie ID.
 */
int Movie::determineID() {
  int kindDigit = static_cast<int>(kind);
  kindDigit %= 10; // 1 digit only.

  int titleDigits = hashStringToInt(getTitle(), 3);

  int yrDigits = releaseYear % 1000; // Limit to 3 digits

  // Combine
  std::string ID_str = std::to_string(kindDigit) + std::to_string(titleDigits) +
                       std::to_string(yrDigits);
  int fullID = std::stoi(ID_str);

  return fullID;
}

/**
 * @return An int with digitLength didigts.
 */
int Movie::hashStringToInt(std::string str, int digitLength) const {
  int digit = hash<std::string>{}(str);

  // Set size of digits to digit length
  digit %= static_cast<int>(pow(10, (digitLength - 1)));

  return digit;
}

int Movie::getStock() const { return stock; }

// Adds 1 to stock
void Movie::addStock() { stock += 1; }

// Subtracts 1 from stock if stock > 0.
bool Movie::remStock() {
  if (stock <= 0) {
    return false;
  }

  stock -= 1;
  return true;
}

string Movie::getDirector() const { return director; }

string Movie::getTitle() const { return title; }

int Movie::getReleaseYear() const { return releaseYear; }

Movie::MovieKind Movie::getKind() const { return kind; }

int Movie::getID() const { return ID; }

std::ostream &Movie::display(std::ostream &os) const {
  os << getKind() << ", " << getStock() << ", " << getDirector() << ", "
     << getTitle() << " " << getReleaseYear();
  return os;
}

std::ostream &operator<<(std::ostream &os, const Movie &movie) {

  if (movie.PRINT_ID) {
    os << std::string("[ID: ") << std::to_string(movie.getID())
       << std::string("] ");
  }

  movie.display(os);

  return os;
}

// ===================================

ComedyMovie::ComedyMovie(int stock, std::string director, std::string title,
                         int releaseYear)
    : Movie(stock, director, title, releaseYear, COMEDY) {}

// To store the data in the system, the items should be sorted as follows:
// comedy movies (‘F’) sorted by Title, then Year it released
// dramas (‘D’) are sorted by Director, then Title
// classics (‘C’) are sorted by Release date, then Major actor
bool ComedyMovie::operator<(const Movie &rhs) const {
  if (rhs.getKind() != COMEDY) {
    return COMEDY < rhs.getKind();
  }

  // comedy movies (‘F’) sorted by Title, then Year it released
  const ComedyMovie &right = static_cast<const ComedyMovie &>(rhs);
  if (this->getTitle() != right.getTitle()) {
    return this->getTitle() < right.getTitle();
  }

  return this->getReleaseYear() < right.getReleaseYear();
}

bool ComedyMovie::operator>(const Movie &rhs) const {
  if (rhs.getKind() != COMEDY) {
    return COMEDY > rhs.getKind();
  }

  // comedy movies (‘F’) sorted by Title, then Year it released
  const ComedyMovie &right = static_cast<const ComedyMovie &>(rhs);
  if (this->getTitle() != right.getTitle()) {
    return this->getTitle() > right.getTitle();
  }

  return this->getReleaseYear() > right.getReleaseYear();
}

bool ComedyMovie::operator==(const Movie &rhs) const {
  if (rhs.getKind() != COMEDY) {
    std::cout << "rhs NOT comedy" << std::endl; // DELETE ME
    return false;
  }

  // comedy movies (‘F’) sorted by Title, then Year it released
  const ComedyMovie &right = static_cast<const ComedyMovie &>(rhs);
  return this->getTitle() == right.getTitle() &&
         this->getReleaseYear() == right.getReleaseYear();
}

bool ComedyMovie::operator<=(const Movie &rhs) const {
  return *this < rhs || *this == rhs;
}

bool ComedyMovie::operator>=(const Movie &rhs) const {
  return *this > rhs || *this == rhs;
}

// ===================================

DramaMovie::DramaMovie(int stock, std::string director, std::string title,
                       int releaseYear)
    : Movie(stock, director, title, releaseYear, DRAMA) {}

bool DramaMovie::operator<(const Movie &rhs) const {
  if (rhs.getKind() != DRAMA) {
    return DRAMA < rhs.getKind();
  }
  // dramas (‘D’) are sorted by Director, then Title
  if (this->getDirector() != rhs.getDirector()) {
    return this->getDirector() < rhs.getDirector();
  }
  return this->getTitle() < rhs.getTitle();
}

bool DramaMovie::operator>(const Movie &rhs) const {
  if (rhs.getKind() != DRAMA) {
    return DRAMA > rhs.getKind();
  }
  // Dramas ('D') are sorted by Director, then Title
  if (this->getDirector() != rhs.getDirector()) {
    return this->getDirector() > rhs.getDirector();
  }
  return this->getTitle() > rhs.getTitle();
}

bool DramaMovie::operator==(const Movie &rhs) const {
  if (rhs.getKind() != DRAMA) {
    return false;
  }
  // Dramas ('D') are sorted by Director, then Title
  return this->getDirector() == rhs.getDirector() &&
         this->getTitle() == rhs.getTitle();
}

bool DramaMovie::operator<=(const Movie &rhs) const {
  return *this < rhs || *this == rhs;
}

bool DramaMovie::operator>=(const Movie &rhs) const {
  return *this > rhs || *this == rhs;
}

// ===================================

ClassicMovie::ClassicMovie(int stock, std::string director, std::string title,
                           std::string majorActor, int releaseMonth,
                           int releaseYear)
    : Movie(stock, director, title, releaseYear, CLASSIC),
      releaseMonth(releaseMonth) {}

string ClassicMovie::getMajorActor() const { return majorActor; }

int ClassicMovie::getReleaseMonth() const { return releaseMonth; }

bool ClassicMovie::operator<(const Movie &rhs) const {
  if (rhs.getKind() != CLASSIC) {
    return CLASSIC < rhs.getKind();
  }
  // dramas (‘D’) are sorted by Director, then Title
  if (this->getDirector() != rhs.getDirector()) {
    return this->getDirector() < rhs.getDirector();
  }
  return this->getTitle() < rhs.getTitle();
}

bool ClassicMovie::operator>(const Movie &rhs) const {
  if (rhs.getKind() != CLASSIC) {
    return CLASSIC > rhs.getKind();
  }
  // Dramas ('D') are sorted by Director, then Title
  if (this->getDirector() != rhs.getDirector()) {
    return this->getDirector() > rhs.getDirector();
  }
  return this->getTitle() > rhs.getTitle();
}

bool ClassicMovie::operator==(const Movie &rhs) const {
  if (rhs.getKind() != CLASSIC) {
    return false;
  }
  // Dramas ('D') are sorted by Director, then Title
  return this->getDirector() == rhs.getDirector() &&
         this->getTitle() == rhs.getTitle();
}

bool ClassicMovie::operator<=(const Movie &rhs) const {
  return *this < rhs || *this == rhs;
}

bool ClassicMovie::operator>=(const Movie &rhs) const {
  return *this > rhs || *this == rhs;
}

std::ostream &ClassicMovie::display(std::ostream &os) const {
  os << getKind() << ", " << getStock() << ", " << getDirector() << ", "
     << getTitle() << ", " << getMajorActor() << " " << getReleaseMonth() << " "
     << getReleaseYear();
  return os;
}

/**
 * =================================
 * Factory Class for Movie
 */
#include <sstream>

Movie *MovieFactory::determineMovie(std::string movieInfo) {
  std::string movieTypeStr = "";
  std::string director = "";
  std::string title = "";
  std::string majorActor = "";
  std::string actorFirstName = "";
  std::string actorLastName = "";
  std::string releaseYearStr = "";
  std::string stockStr = "";
  int stock = 0;
  int releaseYear = 0;
  int releaseMonth = 0;
  char movieType;

  Movie *movie = nullptr;

  std::istringstream iss(movieInfo);

  if (std::getline(iss, movieTypeStr, ',') &&
      std::getline(iss, stockStr, ',') && std::getline(iss, director, ',') &&
      std::getline(iss, title, ',')) {

    std::cout << movieTypeStr << stockStr << director << title << std::endl;
    std::cout << movieTypeStr[0] << std::endl;
    std::cout << movieTypeStr[1] << std::endl;
    movieType = movieTypeStr[0];

    // Convert strings to ints
    stock = std::stoi(stockStr);

    switch (movieTypeStr[0]) {
    case 'F': // Comedy
      if (std::getline(iss, releaseYearStr, ',')) {
        releaseYear = std::stoi(releaseYearStr);

        movie = new ComedyMovie(stock, director, title, releaseYear);
      }
      break;

    case 'D': // Drama
      if (std::getline(iss, releaseYearStr, ',')) {
        releaseYear = std::stoi(releaseYearStr);

        movie = new DramaMovie(stock, director, title, releaseYear);
      }
      break;

    case 'C': // Classic
      if (iss >> actorFirstName >> actorLastName >> releaseMonth >>
          releaseYear) {

        majorActor = actorFirstName + " " + actorLastName;

        movie = new ClassicMovie(stock, director, title, majorActor,
                                 releaseMonth, releaseYear);
      }
      break;

      /**
      default:
        std::cout << "Movie Genre Type '" << movieTypeStr[0] << "' is invalid."
                  << std::endl;
        */
    }
  }

  return movie;
}