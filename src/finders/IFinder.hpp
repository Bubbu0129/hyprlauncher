#pragma once

#include <string>
#include <vector>
#include <optional>

#include "../helpers/Memory.hpp"

class IFinderResult;

enum class eFinderTypes {
    FINDER_DESKTOP = 0,
    FINDER_UNICODE,
    FINDER_MATH,
    FINDER_IPC,
    FINDER_FONT,
};

struct SFinderResult {
    std::string                label;
    std::string                icon;
    SP<IFinderResult>          result;
    std::optional<std::string> overrideFont = std::nullopt;
    bool                       hasIcon       = false;
    bool                       hasMatches    = true;  // Track if results are real fuzzy matches
};

class IFinder {
  public:
    virtual ~IFinder() = default;

    virtual std::vector<SFinderResult> getResultsForQuery(const std::string& query) = 0;
    virtual void                       init()                                          = 0;
};
