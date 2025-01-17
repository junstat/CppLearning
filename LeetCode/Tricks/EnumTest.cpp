#include <map>
#include <string>
#include <cinttypes>
#include <gtest/gtest.h>
#include <fmt/format.h>

using namespace std;

#define WEEK_TABLE() \
DEF_WEEK(WEEK_SUNDAY, 0, "Sunday") \
DEF_WEEK(WEEK_MONDAY, 1, "Monday") \
DEF_WEEK(WEEK_TUESDAY, 2, "Tuesday") \
DEF_WEEK(WEEK_WEDNESDAY, 3, "Wednesday") \
DEF_WEEK(WEEK_THURSDAY, 4, "Thursday")   \
DEF_WEEK(WEEK_FRIDAY, 5, "Friday") \
DEF_WEEK(WEEK_SATURDAY, 6, "Saturday")   \
/* ( end ) */

enum Week : int32_t {
#define DEF_WEEK(name, id, desc) name = id,
    WEEK_TABLE()
#undef DEF_WEEK
};

static inline auto IsValidWeek(Week week) -> bool {
    switch (week) {
#define DEF_WEEK(name, id, desc) \
    case Week::name: \
        return true;
        WEEK_TABLE()
#undef DEF_WEEK
        default:
            return false;
    }
}

struct Day {
    int32_t week{-1};

    explicit Day(int32_t week) : week(week) {}

    [[nodiscard]] auto toString() const -> string {
        switch (week) {
#define DEF_WEEK(name, id, desc) \
    case Week::name: \
        return desc; \
        break;
            WEEK_TABLE()
#undef DEF_WEEK
            default:
                return "";
        }
    }
};

static const map<string, int32_t> weekMap = {
#define DEF_WEEK(name, id, desc) {(desc), (id)},
    WEEK_TABLE()
#undef DEF_WEEK
};

TEST(EnumTest, example1) {
    ASSERT_TRUE(IsValidWeek(Week::WEEK_MONDAY));
    ASSERT_TRUE(IsValidWeek(Week::WEEK_TUESDAY));
    ASSERT_TRUE(IsValidWeek(Week::WEEK_WEDNESDAY));
    ASSERT_TRUE(IsValidWeek(Week::WEEK_THURSDAY));
    ASSERT_TRUE(IsValidWeek(Week::WEEK_FRIDAY));
    ASSERT_TRUE(IsValidWeek(Week::WEEK_SATURDAY));
    ASSERT_FALSE(IsValidWeek(static_cast<Week>(7)));
}

TEST(EnumTest, example2) {
    Day day(weekMap.at("Monday"));
    ASSERT_EQ(day.toString(), "Monday");
}
