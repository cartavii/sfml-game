#ifndef EVENT_HPP
#define EVENT_HPP

#include <functional>
#include <vector>

template<typename... Args>
class Event {
public:
    using Handler  = std::function<void(Args...)>;

    void subscribe(Handler handler);

    void emit(Args... args);

private:
    std::vector<Handler> m_Handlers;
};

template<typename ... Args>
void Event<Args...>::subscribe(Handler handler) {
    m_Handlers.push_back(std::move(handler));
}

template<typename ... Args>
void Event<Args...>::emit(Args... args) {
    for (const auto& handler : m_Handlers) {
        if (handler) {
            handler(args...);
        }
    }
}

#endif //EVENT_HPP
