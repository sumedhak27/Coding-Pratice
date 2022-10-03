// https://godbolt.org/#z:OYLghAFBqd5TKALEBjA9gEwKYFFMCWALugE4A0BIEAZgQDbYB2AhgLbYgDkAjF%2BTXRMiAZVQtGIHgBYBQogFUAztgAKAD24AGfgCsp5eiyahUAUgBMAIUtXyKxqiIEh1ZpgDC6egFc2TEAsLcncAGQImbAA5PwAjbFIpHnIAB3QlYhcmL19/QOC0jOchcMiYtnjEnmSHbCcskSIWUiIcvwCg%2B2xHYqZG5qJS6LiEpPsmlra8zqUJwYjhitHqgEp7dB9SVE4uSwBmCNRfHABqMz2PF1nSbHZz3DMtAEF9w%2BPsM4uONjIAT3vHi8LAcmEcfKdzh42D4iNh1ADnq9Qe9Ph4iEgbixMAigSCwRCLgA3OokUg4wGzFjOVAnCJEE4YHzCc42RHPI4sJRKE4AWV%2BPPQWDOAHZWU8TicUqQCISqZxARKJbNMCAQNcIsATj8sCyFYrKdSTsrVUokM1sJgAPopIhki58gU6va4WlMSmg7C656Ko1NQ3GkDQ2HqE70dCoADWXvFiodgswEBWIrFPp9AHo076VWgNvTIZCzkE41hVYnLBZUQWA%2B56NHU4rGczrLY6/WtfHPgARQsWSIw0gScutiVmYWd1spHyxegEVAgPVKv2zrMms03K02u0eYvY50nYDYIiWiLu7aJ5ML1MEGgnCAnpoegB0B6IiZWl7bJxuRE2TFdp89PYUzbAMw0jS1gB8Zpdw8AMgzhe5Q3DCMLQgMCI3fICP0Va9b3vYxtmfQ832w%2Btv1/f8H22YdU3I0g/3wj0uxXNU1wta1bUhHd7ggSIAHdeX5eMSKw71FVHcc2RjCVCXQAhMCNQ9LW1BMMDdekA3VExLAANiNJNR2A%2BsVOYpQaIkwFL0020NUtQkCGwAS2F%2BZThIM0VSK/Q8KJU8yx0s/zRJeZ5NLYjdOPtISnRdHdVUY6igtC81wq3bi9xfY91II7Ay0Sohs3gkNYpAdDo0s55ZPk/clJUpRz0Mqz8tVRk8wuAtioy%2BKcpWABae5nNcrB6rai4WJrMr/KkuktRYCJ6o8sSJQzE4WBhdAjR4ZiOqUrrcqMk5loDFrK1GpQeD650BpU4aPCrJqQHGoL00zVaSCNCtzm7baj12zD9sOiwLtwFQj2u8tdG8f4gj%2By9Dvu4781O87%2Bpc66DJGjwxqYTBayCxrs2JJwyEhAN0UxXcXTJ25MDMp7FUEUg8OEWlmK0FkWYLHg2aA2kW2sdz9p9KmsSUR9J1NS1YhYSMIFJjFqegGr4yUFYYcWkVJOCrWfQZ29XvQXSTiIEAjflkWBc8ohHwhua1ekjX8ea3MTsxxtWtu077sesVLzov9uZ9yata4NZ6G4ABWfgAi4HRyHQbhbubawjQ2LYPn2PhyGNmOQ7WCMQHD4VH2kAAOCwtBkPYS5L0uAE4LGSMOuGkKPtH4eOuH4JQQC0LO27WOBYBQDA2BSBgEkoagR7HxhEmAHhOjoehYVIbuIFiNvyFiCJml%2BbhM5HjhhAAeSYeg95z8gcDYYxgEkS/CBuepiW7y%2B4TqGEdljuluk3mdYgHKQX4XgcCbxsmwfeIcBBGGAEoAAag5Pix8UjMEgXIYQYgJCcBkOgxQKgNCb30I3W%2BaA%2BZ2H/t3SAax0A2iyK/HqNozaYC7t0EkWQ3DYymAEZIYQFjlEqAYQomQhBcMEekYRTAhj8OWF0HoDQ5iiJqKw%2BoQh%2BgtCkSMKo4wBiKO0eovhmipBrCUKnbYBhbTYB2HwUOEdW6Xw7uoEuOkeo6WkPuVANIF6PgrBARONhrDkBOPgYgZBCx7GSCcLwo9x6Mwzisfg2cdCq3IPnaQFhHzhx4MKWuJdw46WqJkrQ2Tw6GG4C3cg0dY4dy7j3PuOdklNwsPwCB4c9jeK0CXHgexhTCh4Jk7JtdhQVM3tUupSTyCD2QCAXMk4iCTwgNPGJUR2A7Ecc41x7jPHpKaSEQgpJ5IGEEBg8QkgcFHLwWoTQl8iHkD4gOFIkCbFcEjsM%2Bx3Bj4wlmScdAN41kuLccADxJwvE%2BKiTPBIYSeDxLGbncgSBqajETKU5uzSQDSB0o%2BbJPAnFBBrmXLQWg9ivKqdwGpvdEmwqbnsOxJLO4wuScSVe7DpBAA%3D

#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

static int count;

class MyMood {
  private:
    std::string mood;
    static std::shared_ptr<MyMood> instance;
    static std::mutex lock;
    MyMood() {
        // std::cout << "MyMood::()" << std::endl;
        count++;
        mood = "neutral";
    };
  public:
    static std::shared_ptr<MyMood> get_instance() {
        if (instance.get())
            return instance;
        std::lock_guard<std::mutex> locked(lock);
        if (instance.get())
            return instance;
        return instance = std::shared_ptr<MyMood>(new MyMood());
    }

    void set_mood(const std::string& s) {
        mood = s;
    }

    std::string_view my_mood() {
        return mood;
    }
};

std::shared_ptr<MyMood> MyMood::instance;
std::shared_ptr<MyMood> get_instance();
std::mutex MyMood::lock;


void get_moods() {
    std::cout << MyMood::get_instance()->my_mood() << std::endl;
}

int main() {
    // auto s1 = MyMood::get_instance();
    // std::cout << s1->my_mood() << std::endl;
    // auto s2 = MyMood::get_instance();
    // s2->set_mood("joly");
    // std::cout << s1->my_mood() << std::endl;

    std::vector<std::thread> threads;
    for (int i = 0; i < 10; i++) {
        threads.push_back(std::thread(get_moods));
    }


    for (auto& t: threads) {
        t.join();
    }
    std::cout << count << std::endl;

    return 0;
}

