#ifndef IRECTANGLECOMMANDS_HPP
#define IRECTANGLECOMMANDS_HPP

#include "IRectangleCommand.hpp"
#include "Rectangles.hpp"
#include "RectangleGenerator.hpp"

class RectangleCommandGenerate : public IRectangleCommand {
public:
    RectangleCommandGenerate(Rectangles& rectangles, const RectangleGenerator& generator);

public:
    void execute() override;

private:
    Rectangles& m_Rectangles;
    const RectangleGenerator& m_Generator;
};

class RectangleCommandClear : public IRectangleCommand {
public:
    RectangleCommandClear(Rectangles& rectangles);

public:
    void execute() override;

private:
    Rectangles& m_Rectangles;
};

class RectangleCommandSave : public IRectangleCommand {
public:
    RectangleCommandSave(Rectangles& rectangles);

public:
    void execute() override;

private:
    Rectangles& m_Rectangles;
};

class RectangleCommandLoadLast : public IRectangleCommand {
public:
    RectangleCommandLoadLast(Rectangles& rectangles);

public:
    void execute() override;

private:
    Rectangles& m_Rectangles;
};

#endif //IRECTANGLECOMMAND_HPP
