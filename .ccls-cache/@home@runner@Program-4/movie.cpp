//
// Created by Andrew on 2/19/2024.
//

#include "movie.h"

using namespace std;

Movie::Movie(int stock, string director, string title, int releaseYear,
             Movie::MovieKind kind)
    : stock(stock), director(director), title(title), kind(kind),
      releaseYear(releaseYear) {
  ID = 0; // TEMP, REMOVE ME
}

int Movie::getStock() const { return stock; }

string Movie::getDirector() const { return director; }

string Movie::getTitle() const { return title; }

int Movie::getReleaseYear() const { return releaseYear; }

Movie::MovieKind Movie::getKind() const { return kind; }

int Movie::getID() const { return ID; }

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
