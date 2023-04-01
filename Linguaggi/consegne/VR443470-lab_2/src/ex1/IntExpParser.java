package ex1;// Generated from C:/Universit�/Linguaggi/Laboratorio/consegne/VR443470-lab_2/src\IntExp.g4 by ANTLR 4.12.0
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class IntExpParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.12.0", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		LPAR=1, RPAR=2, PLUS=3, MULT=4, SUBT=5, DIVI=6, MODU=7, NAT=8, WS=9;
	public static final int
		RULE_main = 0, RULE_exp = 1;
	private static String[] makeRuleNames() {
		return new String[] {
			"main", "exp"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'('", "')'", "'+'", "'*'", "'-'", "'/'", "'mod'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "LPAR", "RPAR", "PLUS", "MULT", "SUBT", "DIVI", "MODU", "NAT", 
			"WS"
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

	@Override
	public String getGrammarFileName() { return "IntExp.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public IntExpParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class MainContext extends ParserRuleContext {
		public ExpContext exp() {
			return getRuleContext(ExpContext.class,0);
		}
		public TerminalNode EOF() { return getToken(IntExpParser.EOF, 0); }
		public MainContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_main; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IntExpVisitor ) return ((IntExpVisitor<? extends T>)visitor).visitMain(this);
			else return visitor.visitChildren(this);
		}
	}

	public final MainContext main() throws RecognitionException {
		MainContext _localctx = new MainContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_main);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(4);
			exp();
			setState(5);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ExpContext extends ParserRuleContext {
		public ExpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_exp; }
	 
		public ExpContext() { }
		public void copyFrom(ExpContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class NatContext extends ExpContext {
		public TerminalNode NAT() { return getToken(IntExpParser.NAT, 0); }
		public NatContext(ExpContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IntExpVisitor ) return ((IntExpVisitor<? extends T>)visitor).visitNat(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class DivContext extends ExpContext {
		public TerminalNode LPAR() { return getToken(IntExpParser.LPAR, 0); }
		public List<ExpContext> exp() {
			return getRuleContexts(ExpContext.class);
		}
		public ExpContext exp(int i) {
			return getRuleContext(ExpContext.class,i);
		}
		public TerminalNode DIVI() { return getToken(IntExpParser.DIVI, 0); }
		public TerminalNode RPAR() { return getToken(IntExpParser.RPAR, 0); }
		public DivContext(ExpContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IntExpVisitor ) return ((IntExpVisitor<? extends T>)visitor).visitDiv(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class SubContext extends ExpContext {
		public TerminalNode LPAR() { return getToken(IntExpParser.LPAR, 0); }
		public List<ExpContext> exp() {
			return getRuleContexts(ExpContext.class);
		}
		public ExpContext exp(int i) {
			return getRuleContext(ExpContext.class,i);
		}
		public TerminalNode SUBT() { return getToken(IntExpParser.SUBT, 0); }
		public TerminalNode RPAR() { return getToken(IntExpParser.RPAR, 0); }
		public SubContext(ExpContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IntExpVisitor ) return ((IntExpVisitor<? extends T>)visitor).visitSub(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ModContext extends ExpContext {
		public TerminalNode LPAR() { return getToken(IntExpParser.LPAR, 0); }
		public List<ExpContext> exp() {
			return getRuleContexts(ExpContext.class);
		}
		public ExpContext exp(int i) {
			return getRuleContext(ExpContext.class,i);
		}
		public TerminalNode MODU() { return getToken(IntExpParser.MODU, 0); }
		public TerminalNode RPAR() { return getToken(IntExpParser.RPAR, 0); }
		public ModContext(ExpContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IntExpVisitor ) return ((IntExpVisitor<? extends T>)visitor).visitMod(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class MulContext extends ExpContext {
		public TerminalNode LPAR() { return getToken(IntExpParser.LPAR, 0); }
		public List<ExpContext> exp() {
			return getRuleContexts(ExpContext.class);
		}
		public ExpContext exp(int i) {
			return getRuleContext(ExpContext.class,i);
		}
		public TerminalNode MULT() { return getToken(IntExpParser.MULT, 0); }
		public TerminalNode RPAR() { return getToken(IntExpParser.RPAR, 0); }
		public MulContext(ExpContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IntExpVisitor ) return ((IntExpVisitor<? extends T>)visitor).visitMul(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class PlusContext extends ExpContext {
		public TerminalNode LPAR() { return getToken(IntExpParser.LPAR, 0); }
		public List<ExpContext> exp() {
			return getRuleContexts(ExpContext.class);
		}
		public ExpContext exp(int i) {
			return getRuleContext(ExpContext.class,i);
		}
		public TerminalNode PLUS() { return getToken(IntExpParser.PLUS, 0); }
		public TerminalNode RPAR() { return getToken(IntExpParser.RPAR, 0); }
		public PlusContext(ExpContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IntExpVisitor ) return ((IntExpVisitor<? extends T>)visitor).visitPlus(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ExpContext exp() throws RecognitionException {
		ExpContext _localctx = new ExpContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_exp);
		try {
			setState(38);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
			case 1:
				_localctx = new NatContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(7);
				match(NAT);
				}
				break;
			case 2:
				_localctx = new PlusContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(8);
				match(LPAR);
				setState(9);
				exp();
				setState(10);
				match(PLUS);
				setState(11);
				exp();
				setState(12);
				match(RPAR);
				}
				break;
			case 3:
				_localctx = new MulContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(14);
				match(LPAR);
				setState(15);
				exp();
				setState(16);
				match(MULT);
				setState(17);
				exp();
				setState(18);
				match(RPAR);
				}
				break;
			case 4:
				_localctx = new SubContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(20);
				match(LPAR);
				setState(21);
				exp();
				setState(22);
				match(SUBT);
				setState(23);
				exp();
				setState(24);
				match(RPAR);
				}
				break;
			case 5:
				_localctx = new DivContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(26);
				match(LPAR);
				setState(27);
				exp();
				setState(28);
				match(DIVI);
				setState(29);
				exp();
				setState(30);
				match(RPAR);
				}
				break;
			case 6:
				_localctx = new ModContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(32);
				match(LPAR);
				setState(33);
				exp();
				setState(34);
				match(MODU);
				setState(35);
				exp();
				setState(36);
				match(RPAR);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\u0004\u0001\t)\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0001"+
		"\u0000\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0003\u0001\'\b\u0001\u0001"+
		"\u0001\u0000\u0000\u0002\u0000\u0002\u0000\u0000+\u0000\u0004\u0001\u0000"+
		"\u0000\u0000\u0002&\u0001\u0000\u0000\u0000\u0004\u0005\u0003\u0002\u0001"+
		"\u0000\u0005\u0006\u0005\u0000\u0000\u0001\u0006\u0001\u0001\u0000\u0000"+
		"\u0000\u0007\'\u0005\b\u0000\u0000\b\t\u0005\u0001\u0000\u0000\t\n\u0003"+
		"\u0002\u0001\u0000\n\u000b\u0005\u0003\u0000\u0000\u000b\f\u0003\u0002"+
		"\u0001\u0000\f\r\u0005\u0002\u0000\u0000\r\'\u0001\u0000\u0000\u0000\u000e"+
		"\u000f\u0005\u0001\u0000\u0000\u000f\u0010\u0003\u0002\u0001\u0000\u0010"+
		"\u0011\u0005\u0004\u0000\u0000\u0011\u0012\u0003\u0002\u0001\u0000\u0012"+
		"\u0013\u0005\u0002\u0000\u0000\u0013\'\u0001\u0000\u0000\u0000\u0014\u0015"+
		"\u0005\u0001\u0000\u0000\u0015\u0016\u0003\u0002\u0001\u0000\u0016\u0017"+
		"\u0005\u0005\u0000\u0000\u0017\u0018\u0003\u0002\u0001\u0000\u0018\u0019"+
		"\u0005\u0002\u0000\u0000\u0019\'\u0001\u0000\u0000\u0000\u001a\u001b\u0005"+
		"\u0001\u0000\u0000\u001b\u001c\u0003\u0002\u0001\u0000\u001c\u001d\u0005"+
		"\u0006\u0000\u0000\u001d\u001e\u0003\u0002\u0001\u0000\u001e\u001f\u0005"+
		"\u0002\u0000\u0000\u001f\'\u0001\u0000\u0000\u0000 !\u0005\u0001\u0000"+
		"\u0000!\"\u0003\u0002\u0001\u0000\"#\u0005\u0007\u0000\u0000#$\u0003\u0002"+
		"\u0001\u0000$%\u0005\u0002\u0000\u0000%\'\u0001\u0000\u0000\u0000&\u0007"+
		"\u0001\u0000\u0000\u0000&\b\u0001\u0000\u0000\u0000&\u000e\u0001\u0000"+
		"\u0000\u0000&\u0014\u0001\u0000\u0000\u0000&\u001a\u0001\u0000\u0000\u0000"+
		"& \u0001\u0000\u0000\u0000\'\u0003\u0001\u0000\u0000\u0000\u0001&";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}