#include <vector>
#include <string>

using namespace std;

class Robot {
public:
    Robot(int width, int height) : w(width), h(height), perimeter(2 * (w + h - 2)) {}

    void step(int k) {
        if (k >= perimeter) {
            k %= perimeter;
            if (x == 0 && y == 0 && dir == 0) dir = 3;
        }
        while (k > 0) {
            auto step = min(k, maxStep());
            k -= step;
            auto &[dx, dy] = dirs[dir];
            x += dx * step;
            y += dy * step;
            if (k) dir = (dir + 1) % 4;
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        return texts[dir];
    }

private:
    int dir = 0, w, h, perimeter, x = 0, y = 0;
    int dirs[4][2] = {{1,  0},
                      {0,  1},
                      {-1, 0},
                      {0,  -1}};
    vector<string> texts = {"East", "North", "West", "South"};

    int maxStep() {
        if (dir == 0) return w - 1 - x;
        if (dir == 1) return h - 1 - y;
        if (dir == 2) return x;
        return y;
    }
};
