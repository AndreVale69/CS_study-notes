// Generated from C:/Università/Linguaggi/Laboratorio/consegne/VR443470-lab_2/src/ex2\IntExp.g4 by ANTLR 4.12.0
package ex2;
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class IntExpLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.12.0", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		LPAR=1, RPAR=2, PLUS=3, SUBT=4, MULT=5, DIVI=6, MODU=7, EQUA=8, ENDL=9, 
		NAT=10, ALF=11, WS=12;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"LPAR", "RPAR", "PLUS", "SUBT", "MULT", "DIVI", "MODU", "EQUA", "ENDL", 
			"NAT", "ALF", "WS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'('", "')'", "'+'", "'-'", "'*'", "'/'", "'mod'", "'='", "';'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "LPAR", "RPAR", "PLUS", "SUBT", "MULT", "DIVI", "MODU", "EQUA", 
			"ENDL", "NAT", "ALF", "WS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public IntExpLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "IntExp.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\u0004\u0000\fK\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002\u0001"+
		"\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004"+
		"\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007"+
		"\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b"+
		"\u0007\u000b\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0002"+
		"\u0001\u0002\u0001\u0003\u0001\u0003\u0001\u0004\u0001\u0004\u0001\u0005"+
		"\u0001\u0005\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0007"+
		"\u0001\u0007\u0001\b\u0001\b\u0001\t\u0001\t\u0001\t\u0005\t1\b\t\n\t"+
		"\f\t4\t\t\u0001\t\u0001\t\u0001\t\u0005\t9\b\t\n\t\f\t<\t\t\u0003\t>\b"+
		"\t\u0001\n\u0004\nA\b\n\u000b\n\f\nB\u0001\u000b\u0004\u000bF\b\u000b"+
		"\u000b\u000b\f\u000bG\u0001\u000b\u0001\u000b\u0000\u0000\f\u0001\u0001"+
		"\u0003\u0002\u0005\u0003\u0007\u0004\t\u0005\u000b\u0006\r\u0007\u000f"+
		"\b\u0011\t\u0013\n\u0015\u000b\u0017\f\u0001\u0000\u0004\u0001\u00001"+
		"9\u0001\u000009\u0001\u0000az\u0003\u0000\t\n\r\r  P\u0000\u0001\u0001"+
		"\u0000\u0000\u0000\u0000\u0003\u0001\u0000\u0000\u0000\u0000\u0005\u0001"+
		"\u0000\u0000\u0000\u0000\u0007\u0001\u0000\u0000\u0000\u0000\t\u0001\u0000"+
		"\u0000\u0000\u0000\u000b\u0001\u0000\u0000\u0000\u0000\r\u0001\u0000\u0000"+
		"\u0000\u0000\u000f\u0001\u0000\u0000\u0000\u0000\u0011\u0001\u0000\u0000"+
		"\u0000\u0000\u0013\u0001\u0000\u0000\u0000\u0000\u0015\u0001\u0000\u0000"+
		"\u0000\u0000\u0017\u0001\u0000\u0000\u0000\u0001\u0019\u0001\u0000\u0000"+
		"\u0000\u0003\u001b\u0001\u0000\u0000\u0000\u0005\u001d\u0001\u0000\u0000"+
		"\u0000\u0007\u001f\u0001\u0000\u0000\u0000\t!\u0001\u0000\u0000\u0000"+
		"\u000b#\u0001\u0000\u0000\u0000\r%\u0001\u0000\u0000\u0000\u000f)\u0001"+
		"\u0000\u0000\u0000\u0011+\u0001\u0000\u0000\u0000\u0013=\u0001\u0000\u0000"+
		"\u0000\u0015@\u0001\u0000\u0000\u0000\u0017E\u0001\u0000\u0000\u0000\u0019"+
		"\u001a\u0005(\u0000\u0000\u001a\u0002\u0001\u0000\u0000\u0000\u001b\u001c"+
		"\u0005)\u0000\u0000\u001c\u0004\u0001\u0000\u0000\u0000\u001d\u001e\u0005"+
		"+\u0000\u0000\u001e\u0006\u0001\u0000\u0000\u0000\u001f \u0005-\u0000"+
		"\u0000 \b\u0001\u0000\u0000\u0000!\"\u0005*\u0000\u0000\"\n\u0001\u0000"+
		"\u0000\u0000#$\u0005/\u0000\u0000$\f\u0001\u0000\u0000\u0000%&\u0005m"+
		"\u0000\u0000&\'\u0005o\u0000\u0000\'(\u0005d\u0000\u0000(\u000e\u0001"+
		"\u0000\u0000\u0000)*\u0005=\u0000\u0000*\u0010\u0001\u0000\u0000\u0000"+
		"+,\u0005;\u0000\u0000,\u0012\u0001\u0000\u0000\u0000->\u00050\u0000\u0000"+
		".2\u0007\u0000\u0000\u0000/1\u0007\u0001\u0000\u00000/\u0001\u0000\u0000"+
		"\u000014\u0001\u0000\u0000\u000020\u0001\u0000\u0000\u000023\u0001\u0000"+
		"\u0000\u00003>\u0001\u0000\u0000\u000042\u0001\u0000\u0000\u000056\u0005"+
		"-\u0000\u00006:\u0007\u0000\u0000\u000079\u0007\u0001\u0000\u000087\u0001"+
		"\u0000\u0000\u00009<\u0001\u0000\u0000\u0000:8\u0001\u0000\u0000\u0000"+
		":;\u0001\u0000\u0000\u0000;>\u0001\u0000\u0000\u0000<:\u0001\u0000\u0000"+
		"\u0000=-\u0001\u0000\u0000\u0000=.\u0001\u0000\u0000\u0000=5\u0001\u0000"+
		"\u0000\u0000>\u0014\u0001\u0000\u0000\u0000?A\u0007\u0002\u0000\u0000"+
		"@?\u0001\u0000\u0000\u0000AB\u0001\u0000\u0000\u0000B@\u0001\u0000\u0000"+
		"\u0000BC\u0001\u0000\u0000\u0000C\u0016\u0001\u0000\u0000\u0000DF\u0007"+
		"\u0003\u0000\u0000ED\u0001\u0000\u0000\u0000FG\u0001\u0000\u0000\u0000"+
		"GE\u0001\u0000\u0000\u0000GH\u0001\u0000\u0000\u0000HI\u0001\u0000\u0000"+
		"\u0000IJ\u0006\u000b\u0000\u0000J\u0018\u0001\u0000\u0000\u0000\u0006"+
		"\u00002:=BG\u0001\u0006\u0000\u0000";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}