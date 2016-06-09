#pragma once

#include <string>
#include <vector>
#include <experimental/optional>

using PileId = unsigned int;

namespace opt = std::experimental;

class Pile
{

public:
    Pile(PileId Id, const std::string& Caption);

    PileId GetId() const;
private:
    PileId      m_Id;
    std::string m_Caption;
};

