/*-
 * Copyright 2014 Diomidis Spinellis
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */

#ifndef PHPTOKENIZER_H
#define PHPTOKENIZER_H

#include <iostream>
#include <sstream>
#include <vector>

#include "CharSource.h"
#include "Keyword.h"
#include "Token.h"
#include "TokenizerBase.h"

/** Collect quality metrics from C-like source code */
class PHPTokenizer : public TokenizerBase {
private:
	Keyword php_keyword;
	Token php_token;
	bool process_here_document();
public:
	int get_token();		// Return a single token

	const std::string & keyword_to_string(int k) const {
		return php_keyword.to_string(k);
	}

	const std::string & token_to_string(int k) const {
		return php_token.to_string(k);
	}

	const std::string & token_to_symbol(int k) const {
		return php_token.to_symbol(k);
	}

	// Construct from a character source
	PHPTokenizer(CharSource &s, const std::string &file_name,
			std::vector<std::string> opt = {}) :
		TokenizerBase(s, file_name, opt) { }

	// Construct for a string source
	PHPTokenizer(const std::string &s, std::vector<std::string> opt = {}) :
		TokenizerBase(s, opt) { }

	~PHPTokenizer();

	friend class PHPTokenizerTest;
};
#endif /* PHPTOKENIZER_H */