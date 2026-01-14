#include "RectangleCommands.hpp"

RectangleCommandGenerate::RectangleCommandGenerate(Rectangles& rectangles, const RectangleGenerator& generator)
: m_Rectangles(rectangles), m_Generator(generator) {}

void RectangleCommandGenerate::execute() {
    m_Rectangles.addRectangle(m_Generator.generate());
}

RectangleCommandClear::RectangleCommandClear(Rectangles& rectangles)
: m_Rectangles(rectangles) {}

void RectangleCommandClear::execute() {
    m_Rectangles.clear();
}

RectangleCommandSave::RectangleCommandSave(Rectangles& rectangles, IRectangleStorage& storage)
: m_Rectangles(rectangles)
, m_Storage(storage) {}

void RectangleCommandSave::execute() {
    m_Storage.save(m_Rectangles);
}

RectangleCommandLoadLast::RectangleCommandLoadLast(Rectangles& rectangles, IRectangleStorage& storage)
: m_Rectangles(rectangles)
, m_Storage(storage) {}

void RectangleCommandLoadLast::execute() {
    m_Rectangles.clear();
    m_Storage.load(m_Rectangles);
}
