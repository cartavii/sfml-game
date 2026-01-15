#ifndef IRANDOM_HPP
#define IRANDOM_HPP

template<typename T>
class IRandom {
public:
    virtual ~IRandom() = default;

public:
    virtual T getRandom() = 0;
};

#endif //IRANDOM_HPP
