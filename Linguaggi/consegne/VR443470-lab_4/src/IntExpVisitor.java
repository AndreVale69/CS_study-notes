// Generated from C:/Università/Linguaggi/Laboratorio/consegne/VR443470-lab_4/src\IntExp.g4 by ANTLR 4.12.0
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link IntExpParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface IntExpVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link IntExpParser#main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMain(IntExpParser.MainContext ctx);
	/**
	 * Visit a parse tree produced by {@link IntExpParser#begin}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBegin(IntExpParser.BeginContext ctx);
	/**
	 * Visit a parse tree produced by {@link IntExpParser#dec}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDec(IntExpParser.DecContext ctx);
	/**
	 * Visit a parse tree produced by the {@code pote}
	 * labeled alternative in {@link IntExpParser#exp}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPote(IntExpParser.PoteContext ctx);
	/**
	 * Visit a parse tree produced by the {@code multDiviModu}
	 * labeled alternative in {@link IntExpParser#exp}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMultDiviModu(IntExpParser.MultDiviModuContext ctx);
	/**
	 * Visit a parse tree produced by the {@code plusSubt}
	 * labeled alternative in {@link IntExpParser#exp}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPlusSubt(IntExpParser.PlusSubtContext ctx);
	/**
	 * Visit a parse tree produced by the {@code alf}
	 * labeled alternative in {@link IntExpParser#exp}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAlf(IntExpParser.AlfContext ctx);
	/**
	 * Visit a parse tree produced by the {@code expCont}
	 * labeled alternative in {@link IntExpParser#exp}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpCont(IntExpParser.ExpContContext ctx);
	/**
	 * Visit a parse tree produced by the {@code float}
	 * labeled alternative in {@link IntExpParser#exp}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFloat(IntExpParser.FloatContext ctx);
}