#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../HTML_Decode/HTMLDecode.h"

TEST_CASE("Empty string must be empty")
{
	std::string html;
	std::string decodedHtml;

	CHECK(HtmlDecode(html) == decodedHtml);
}

TEST_CASE("String without html entity will not change")
{
	std::string html = "Hello world!";
	std::string decodedHtml = "Hello world!";

	CHECK(HtmlDecode(html) == decodedHtml);
}

TEST_CASE("Html entities must be replaced to their character representation")
{
	std::string html = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
	std::string decodedHtml = "Cat <says> \"Meow\". M&M's";

	CHECK(HtmlDecode(html) == decodedHtml);

	html = "&&amp;;&lt;&&gt;";
	decodedHtml = "&&;<&>";

	CHECK(HtmlDecode(html) == decodedHtml);
}