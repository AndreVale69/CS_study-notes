// Generated from C:/Università/Linguaggi/Laboratorio/consegne/VR443470-lab_4/src\IntExp.g4 by ANTLR 4.12.0
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
		LPAR=1, RPAR=2, PLUS=3, SUBT=4, MULT=5, DIVI=6, POTE=7, MODU=8, EQUA=9, 
		ENDL=10, FLOAT=11, ALF=12, WS=13;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"LPAR", "RPAR", "PLUS", "SUBT", "MULT", "DIVI", "POTE", "MODU", "EQUA", 
			"ENDL", "FLOAT", "INTEGER", "NAT", "NUM", "NUMBS", "POSNUMBS", "ALF", 
			"WS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'('", "')'", "'+'", "'-'", "'*'", "'/'", "'^'", "'mod'", "'='", 
			"';'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "LPAR", "RPAR", "PLUS", "SUBT", "MULT", "DIVI", "POTE", "MODU", 
			"EQUA", "ENDL", "FLOAT", "ALF", "WS"
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
		"\u0004\u0000\rk\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002\u0001"+
		"\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004"+
		"\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007"+
		"\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b"+
		"\u0007\u000b\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002"+
		"\u000f\u0007\u000f\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0001"+
		"\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0002\u0001\u0002\u0001"+
		"\u0003\u0001\u0003\u0001\u0004\u0001\u0004\u0001\u0005\u0001\u0005\u0001"+
		"\u0006\u0001\u0006\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001"+
		"\b\u0001\b\u0001\t\u0001\t\u0001\n\u0001\n\u0001\n\u0001\n\u0003\n@\b"+
		"\n\u0001\n\u0001\n\u0004\nD\b\n\u000b\n\f\nE\u0003\nH\b\n\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0003\u000bM\b\u000b\u0001\f\u0001\f\u0003\f"+
		"Q\b\f\u0001\r\u0001\r\u0005\rU\b\r\n\r\f\rX\t\r\u0001\u000e\u0001\u000e"+
		"\u0003\u000e\\\b\u000e\u0001\u000f\u0001\u000f\u0001\u0010\u0004\u0010"+
		"a\b\u0010\u000b\u0010\f\u0010b\u0001\u0011\u0004\u0011f\b\u0011\u000b"+
		"\u0011\f\u0011g\u0001\u0011\u0001\u0011\u0000\u0000\u0012\u0001\u0001"+
		"\u0003\u0002\u0005\u0003\u0007\u0004\t\u0005\u000b\u0006\r\u0007\u000f"+
		"\b\u0011\t\u0013\n\u0015\u000b\u0017\u0000\u0019\u0000\u001b\u0000\u001d"+
		"\u0000\u001f\u0000!\f#\r\u0001\u0000\u0003\u0001\u000019\u0001\u0000a"+
		"z\u0003\u0000\t\n\r\r  n\u0000\u0001\u0001\u0000\u0000\u0000\u0000\u0003"+
		"\u0001\u0000\u0000\u0000\u0000\u0005\u0001\u0000\u0000\u0000\u0000\u0007"+
		"\u0001\u0000\u0000\u0000\u0000\t\u0001\u0000\u0000\u0000\u0000\u000b\u0001"+
		"\u0000\u0000\u0000\u0000\r\u0001\u0000\u0000\u0000\u0000\u000f\u0001\u0000"+
		"\u0000\u0000\u0000\u0011\u0001\u0000\u0000\u0000\u0000\u0013\u0001\u0000"+
		"\u0000\u0000\u0000\u0015\u0001\u0000\u0000\u0000\u0000!\u0001\u0000\u0000"+
		"\u0000\u0000#\u0001\u0000\u0000\u0000\u0001%\u0001\u0000\u0000\u0000\u0003"+
		"\'\u0001\u0000\u0000\u0000\u0005)\u0001\u0000\u0000\u0000\u0007+\u0001"+
		"\u0000\u0000\u0000\t-\u0001\u0000\u0000\u0000\u000b/\u0001\u0000\u0000"+
		"\u0000\r1\u0001\u0000\u0000\u0000\u000f3\u0001\u0000\u0000\u0000\u0011"+
		"7\u0001\u0000\u0000\u0000\u00139\u0001\u0000\u0000\u0000\u0015G\u0001"+
		"\u0000\u0000\u0000\u0017L\u0001\u0000\u0000\u0000\u0019P\u0001\u0000\u0000"+
		"\u0000\u001bR\u0001\u0000\u0000\u0000\u001d[\u0001\u0000\u0000\u0000\u001f"+
		"]\u0001\u0000\u0000\u0000!`\u0001\u0000\u0000\u0000#e\u0001\u0000\u0000"+
		"\u0000%&\u0005(\u0000\u0000&\u0002\u0001\u0000\u0000\u0000\'(\u0005)\u0000"+
		"\u0000(\u0004\u0001\u0000\u0000\u0000)*\u0005+\u0000\u0000*\u0006\u0001"+
		"\u0000\u0000\u0000+,\u0005-\u0000\u0000,\b\u0001\u0000\u0000\u0000-.\u0005"+
		"*\u0000\u0000.\n\u0001\u0000\u0000\u0000/0\u0005/\u0000\u00000\f\u0001"+
		"\u0000\u0000\u000012\u0005^\u0000\u00002\u000e\u0001\u0000\u0000\u0000"+
		"34\u0005m\u0000\u000045\u0005o\u0000\u000056\u0005d\u0000\u00006\u0010"+
		"\u0001\u0000\u0000\u000078\u0005=\u0000\u00008\u0012\u0001\u0000\u0000"+
		"\u00009:\u0005;\u0000\u0000:\u0014\u0001\u0000\u0000\u0000;H\u0003\u0017"+
		"\u000b\u0000<@\u0003\u0017\u000b\u0000=>\u0005-\u0000\u0000>@\u00050\u0000"+
		"\u0000?<\u0001\u0000\u0000\u0000?=\u0001\u0000\u0000\u0000@A\u0001\u0000"+
		"\u0000\u0000AC\u0005.\u0000\u0000BD\u0003\u001d\u000e\u0000CB\u0001\u0000"+
		"\u0000\u0000DE\u0001\u0000\u0000\u0000EC\u0001\u0000\u0000\u0000EF\u0001"+
		"\u0000\u0000\u0000FH\u0001\u0000\u0000\u0000G;\u0001\u0000\u0000\u0000"+
		"G?\u0001\u0000\u0000\u0000H\u0016\u0001\u0000\u0000\u0000IM\u0003\u0019"+
		"\f\u0000JK\u0005-\u0000\u0000KM\u0003\u001b\r\u0000LI\u0001\u0000\u0000"+
		"\u0000LJ\u0001\u0000\u0000\u0000M\u0018\u0001\u0000\u0000\u0000NQ\u0005"+
		"0\u0000\u0000OQ\u0003\u001b\r\u0000PN\u0001\u0000\u0000\u0000PO\u0001"+
		"\u0000\u0000\u0000Q\u001a\u0001\u0000\u0000\u0000RV\u0003\u001f\u000f"+
		"\u0000SU\u0003\u001d\u000e\u0000TS\u0001\u0000\u0000\u0000UX\u0001\u0000"+
		"\u0000\u0000VT\u0001\u0000\u0000\u0000VW\u0001\u0000\u0000\u0000W\u001c"+
		"\u0001\u0000\u0000\u0000XV\u0001\u0000\u0000\u0000Y\\\u00050\u0000\u0000"+
		"Z\\\u0003\u001f\u000f\u0000[Y\u0001\u0000\u0000\u0000[Z\u0001\u0000\u0000"+
		"\u0000\\\u001e\u0001\u0000\u0000\u0000]^\u0007\u0000\u0000\u0000^ \u0001"+
		"\u0000\u0000\u0000_a\u0007\u0001\u0000\u0000`_\u0001\u0000\u0000\u0000"+
		"ab\u0001\u0000\u0000\u0000b`\u0001\u0000\u0000\u0000bc\u0001\u0000\u0000"+
		"\u0000c\"\u0001\u0000\u0000\u0000df\u0007\u0002\u0000\u0000ed\u0001\u0000"+
		"\u0000\u0000fg\u0001\u0000\u0000\u0000ge\u0001\u0000\u0000\u0000gh\u0001"+
		"\u0000\u0000\u0000hi\u0001\u0000\u0000\u0000ij\u0006\u0011\u0000\u0000"+
		"j$\u0001\u0000\u0000\u0000\n\u0000?EGLPV[bg\u0001\u0006\u0000\u0000";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}