consteval int sqr(int n) {
  return n*n;
}
constexpr int r = sqr(100); // OK
  
consteval int sqrsqr(int n) {
  return sqr(sqr(n));       // Not a constant expression at this point, but OK
}

int main() {
    return 0;
}
