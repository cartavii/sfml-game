#ifndef IRECTANGLECOMMANDS_HPP
#define IRECTANGLECOMMANDS_HPP

#include "IRectangleCommand.hpp"
#include "Rectangles.hpp"
#include "RectangleGenerator.hpp"
#include "IRectangleStorage.hpp"

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
    RectangleCommandSave(Rectangles& rectangles, IRectangleStorage& storage);

public:
    void execute() override;

private:
    Rectangles& m_Rectangles;
    IRectangleStorage& m_Storage;
};

class RectangleCommandLoadLast : public IRectangleCommand {
public:
    RectangleCommandLoadLast(Rectangles& rectangles, IRectangleStorage& storage);

public:
    void execute() override;

private:
    Rectangles& m_Rectangles;
    IRectangleStorage& m_Storage;
};

#endif //IRECTANGLECOMMAND_HPP
