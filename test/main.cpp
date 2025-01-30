#include <kv_data/kv_data.h>

using namespace kv;

int main() {
    constexpr std::array<std::string_view, 4> keys = {
        "first", "second", "third", "fourth"
    };

    constexpr std::string_view test_data =
        "first'value1',second'value2',third'value3',fourth'value4'";

    kv_data data(test_data);

    for (auto i : keys) {
        data[i]->key.print();
        data[i]->value.print();
    }

    std::cout << data.to_json() << '\n';

    /*
    output:
    first
    value1
    second
    value2
    third
    value3
    fourth
    value4
    {"fourth":"value4","third":"value3","second":"value2","first":"value1"}
    */

    return 0;
}
