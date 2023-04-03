package ex2;

import java.util.*;

public class IntExp extends IntExpBaseVisitor<Integer> {
    /**
     * The Map object where save all variables used in the expressions
     */
    private final Map<String, Integer> vars = new HashMap<>();

    /**
     * The start point
     * @param ctx the parse tree
     * @return the tree visited
     */
    @Override
    public Integer visitMain(IntExpParser.MainContext ctx) {
        return visit(ctx.begin());
    }

    /**
     * Initialize all variables and obtain the final result
     * @param ctx the parse tree
     * @return result of the final expression
     */
    @Override
    public Integer visitBegin(IntExpParser.BeginContext ctx) {
        // Initialize all variables
        visit(ctx.dec());
        return visit(ctx.exp());
    }

    /**
     * Declaration all variables
     * @param ctx the parse tree
     * @return visit declaration action
     */
    @Override
    public Integer visitAssignm(IntExpParser.AssignmContext ctx) {
        // Take name of variable
        String NameVal = ctx.ALF().getText();
        // Take value of variable
        Integer ValueVal = visit(ctx.exp());

        // Save variable
        vars.put(NameVal, ValueVal);

        // Return to the declaration
        return visit(ctx.dec());
    }

    /**
     * Null
     * @param ctx the parse tree
     * @return null
     */
    @Override
    public Integer visitNullassignm(IntExpParser.NullassignmContext ctx) {
        return null;
    }

    /**
     * Get the var
     * @param ctx the parse tree
     * @return value of var or zero (default)
     */
    @Override
    public Integer visitAlf(IntExpParser.AlfContext ctx) {
        // Take the value from the Map
        Integer value = vars.get(ctx.ALF().getText());
        // Return the value if it's not null, otherwise 0
        return Objects.requireNonNullElse(value, 0);
    }

    /**
     * Plus operation
     * @param ctx the parse tree
     * @return result plus operation
     */
    @Override
    public Integer visitPlus(IntExpParser.PlusContext ctx) {
        int left = visit(ctx.exp(0));
        int right = visit(ctx.exp(1));
        return left + right;
    }

    /**
     * Subtraction operation
     * @param ctx the parse tree
     * @return result subtraction operation
     */
    @Override
    public Integer visitSub(IntExpParser.SubContext ctx) {
        int left = visit(ctx.exp(0));
        int right = visit(ctx.exp(1));
        return left - right;
    }

    /**
     * Multiplication operation
     * @param ctx the parse tree
     * @return result multiplication operation
     */
    @Override
    public Integer visitMul(IntExpParser.MulContext ctx) {
        int left = visit(ctx.exp(0));
        int right = visit(ctx.exp(1));
        return left * right;
    }

    /**
     * Division operation
     * @param ctx the parse tree
     * @return result division operation
     */
    @Override
    public Integer visitDiv(IntExpParser.DivContext ctx) {
        int left = visit(ctx.exp(0));
        int right = visit(ctx.exp(1));
        return left / right;
    }

    /**
     * Module operation
     * @param ctx the parse tree
     * @return result module operation
     */
    @Override
    public Integer visitMod(IntExpParser.ModContext ctx) {
        int left = visit(ctx.exp(0));
        int right = visit(ctx.exp(1));
        return left % right;
    }

    /**
     * Natural numbers
     * @param ctx the parse tree
     * @return Natural numbers
     */
    @Override
    public Integer visitNat(IntExpParser.NatContext ctx) {
        return Integer.parseInt(ctx.NAT().getText());
    }
}
