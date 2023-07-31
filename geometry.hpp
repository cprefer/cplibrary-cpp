template <typename T> struct Point {
  using point = Point<T>;
  T x, y;
  Point(T x = 0, T y = 0) : x(x), y(y) {}
  T dot(const point &rhs) const { return x * rhs.x + y * rhs.y; }
  T len2() const { return dot(*this); };
  point operator+(const point &rhs) const { return point(x + rhs.x, y + rhs.y); }
  point operator-(const point &rhs) const { return point(x - rhs.x, y - rhs.y); }
  point operator*(const T &k) const { return point(x * k, y * k); }
  point operator/(const T &k) const { return point(x / k, y / k); }
  point projection(const point &from, const point &to) const {
    point direction = to - from;
    return from + direction * operator-(from).dot(direction) / direction.len2();
  }
  friend istream &operator>>(istream &is, point &p) { return is >> p.x >> p.y; }
  friend ostream &operator<<(ostream &os, const point &p) { return os << p.x << " " << p.y; }
};