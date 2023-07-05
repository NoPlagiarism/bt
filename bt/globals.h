#pragma once
#include <string>
#include <vector>
#include <chrono>
#include "app/config.h"
#include "ext/lsignal/lsignal.h"

const std::string Win32ClassName("BTWindow");
const std::string AppGuid("026741D2-FF77-462B-AD70-4140697C8AE1");

const std::string AppDescription("Redirects open URLs to a browser of your choice.");

const std::string ProtoName = "BrowserTamerHTM";

const std::string PdfProtoName = "BrowserTamerPDF";

const std::string CustomProtoName = "x-bt";

const std::string CoffeePageUrl = "https://www.buymeacoffee.com/alonecoffee";

const std::string ArgSplitter = "|";

/**
 * @brief Global app event. Args:
 * 0 - event name
 * 1, 2 - extras depending on event
*/
extern lsignal::signal<void(const std::string&, const std::string&, const std::string&)> app_event;
