#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define All(i) points[i].x, points[i].y

struct Point {
  double x;
  double y;
};

double distance(int x1, int y1, int x2, int y2) {
  return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

bool is_diamond(struct Point points[]) {
  for (int i = 1, a, b; i < 4; i++) {
    a = 1 < (i + 1) % 4 ? (i + 1) % 4 : 1;
    b = 1 ^ 2 ^ 3 ^ i ^ a;
    if (distance(All(0), All(a)) == distance(All(0), All(b)) && distance(All(i), All(a)) == distance(All(i), All(b)) && distance(All(0), All(a)) == distance(All(i), All(a))) {
      return true;
    }
  }
  return false;
}

void swap(int first, int second, struct Point *points) {
  int temp_x = points[first].x;
  int temp_y = points[first].y;
  points[first].x = points[second].x;
  points[first].y = points[second].y;
  points[second].x = temp_x;
  points[second].y = temp_y;
}

int what_is_it(struct Point points[]) {
  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 4; j++) {
      for (int k = j + 1; k < 4; k++) {
        if ((points[i].y - points[j].y) / (points[i].x - points[j].x) == (points[i].y - points[k].y) /  (points[i].x - points[k].x)) {
          // set z to other value between i j k fron {0, 1, 2, 3}
          int z = 0 ^ 1 ^ 2 ^ 3 ^ i ^ j ^ k;
          if ((points[i].y - points[j].y) / (points[i].x - points[j].x) == (points[i].y - points[z].y) / (points[i].x - points[z].x)) {
            return 1;
          } else {
            return 2;
          }
        }
      }
    }
  }

  if (is_diamond(points)) {
    return 3;
  } else {
    return 0;
  }
}

int main(int argc, char const *argv[]) {
  struct Point points[4];

  // get input
  for (int i = 0; i < 4; i++) {
    printf("please enter x%d and y%d: ", i + 1, i + 1);
    scanf("%lf %lf", &points[i].x, &points[i].y);
  }

  // sort array by x
  for (int i = 3; i >= 0; i--) {
    for (int j = 0; j < i; j++) {
      if (points[j].x > points[j + 1].x) {
        swap(j, j + 1, points);
      }
    }
  }

  // print pionts
  // for (int i = 0; i < 4; i++) {
  //   printf("point %d: (%lf, %lf)\n", i, points[i].x, points[i].y);
  // }

  switch (what_is_it(points)) {
    case 1:
      printf("All in one line\n");
    break;
    case 2:
      printf("Three in one line\n");
    break;
    case 3:
      printf("Diamond\n");
    break;
    default:
      printf("None\n");
    break;
  }

  return 0;
}
