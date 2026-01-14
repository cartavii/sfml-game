#ifndef IRECTANGLECOMMAND_HPP
#define IRECTANGLECOMMAND_HPP

class IRectangleCommand {
public:
    virtual ~IRectangleCommand() = default;

public:
    virtual void execute() = 0;
};

#endif //IRECTANGLECOMMAND_HPP
