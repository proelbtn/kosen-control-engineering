double val2rad(int val) {
  return (val - 512) / 512. * 150. * (PI / 180.);
}

double rad2ang(double rad) {
  return rad / (PI / 180.);
}

double ang2rad(double ang) {
  return ang * (PI / 180.);
}

int rad2val(double rad) {
  return (int)(rad / (PI / 180.) / 150. * 512.) + 512;
}
