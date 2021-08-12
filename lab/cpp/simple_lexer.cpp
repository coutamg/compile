#include <iostream>
#include <vector>

using namespace std;

class Token {
public:
	enum TokenType {
		Plus,   // +
		Minus,  // -
		Star,   // *
		Slash,  // /

		GE,     // >=
		GT,     // >
		EQ,     // ==
		LE,     // <=
		LT,     // <

		SemiColon, // ;
		LeftParen, // (
		RightParen,// )

		Assignment,// =

		If,
		Else,
		
		Int,

		Identifier,     //标识符

		IntLiteral,     //整型字面量
		StringLiteral   //字符串字面量
	};

public :
	void 

	void SetTokenType(TokenType type) {
		_type = type;
	}

	TokenType GetTokenType() {
		return _type;
	}

	void SetTokenContext(const string& context) {
		_context = context;
	}

	string GetTokenContext() {
		return _context;
	}
private:
	TokenType _type;
	string _context;
};

class SimpleLexer {
public:
	enum State {
		Initial,

        If, Id_if1, Id_if2, Else, Id_else1, Id_else2, Id_else3, Id_else4, Int, Id_int1, Id_int2, Id_int3, Id, GT, GE,

        Assignment,

        Plus, Minus, Star, Slash,

        SemiColon,
        LeftParen,
        RightParen,

        IntLiteral
	};

public:
	State InitToken(const char ch) {
		if (!_tokenContext.empty()) {
			_tokens.emplace_back(_token);
		}
	}

private:
	vector<Token> _tokens; //保存解析出来的Token
	Token _token; //当前正在解析的Token
	string _tokenContext; //临时保存token的文本
};
