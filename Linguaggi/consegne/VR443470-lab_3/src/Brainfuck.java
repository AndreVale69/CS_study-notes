import java.util.HashMap;
import java.util.Map;
import java.util.Objects;
import java.util.Scanner;

public class Brainfuck extends BrainfuckBaseVisitor<Integer> {
    // Tuple of Index,Value
    private final Map<Integer,Integer> tape = new HashMap<>();
    // Live index in the tape
    private int index = 0;

    /**
     * Main tree
     * @param ctx the parse tree
     * @return visit tree
     */
    @Override
    public Integer visitMain(BrainfuckParser.MainContext ctx) {
        return visit(ctx.com());
    }

    /**
     * Decrease the index of the tape
     * @param ctx the parse tree
     * @return visit tree
     */
    @Override
    public Integer visitLt(BrainfuckParser.LtContext ctx) {
        index = index - 1;
        return visit(ctx.com());
    }

    /**
     * Increase the index of the tape
     * @param ctx the parse tree
     * @return visit tree
     */
    @Override
    public Integer visitGt(BrainfuckParser.GtContext ctx) {
        index = index + 1;
        return visit(ctx.com());
    }

    /**
     * Increase the value of the index-position
     * @param ctx the parse tree
     * @return visit tree
     */
    @Override
    public Integer visitPlus(BrainfuckParser.PlusContext ctx) {
        tape.merge(index, 1, Integer::sum);
        return visit(ctx.com());
    }

    /**
     * Decrease the value of the index-position
     * @param ctx the parse tree
     * @return visit tree
     */
    @Override
    public Integer visitMinus(BrainfuckParser.MinusContext ctx) {
        Integer tmpVal = tape.get(index);
        if (tmpVal != null)
            tape.put(index, tmpVal-1);
        else
            tape.put(index, -1);
        return visit(ctx.com());
    }

    /**
     * Print the value in the tape in the index-position
     * @param ctx the parse tree
     * @return visit tree
     */
    @Override
    public Integer visitDot(BrainfuckParser.DotContext ctx) {
        Integer tmpVal = tape.get(index);
        if (tmpVal != null)
            System.out.println(tmpVal);
        else
            System.out.println("0");
        return visit(ctx.com());
    }

    /**
     * Insert a value from input
     * @param ctx the parse tree
     * @return visit tree
     */
    @Override
    public Integer visitComma(BrainfuckParser.CommaContext ctx) {
        final Scanner inputValue = new Scanner(System.in);
        System.out.println("Insert a value in " + index + " position: ");
        tape.put(index, inputValue.nextInt());
        return visit(ctx.com());
    }

    /**
     * Visit the tree until the value is zero
     * @param ctx the parse tree
     * @return visit tree with 1 value
     */
    @Override
    public Integer visitLoop(BrainfuckParser.LoopContext ctx) {
        Integer tmpVal = tape.get(index);
        if (tmpVal == null)
            tmpVal = 0;
        while (tmpVal != 0)
            tmpVal = visit(ctx.com(0));
        return visit(ctx.com(1));
    }

    /**
     * Nil operation
     * @param ctx the parse tree
     * @return value or 0 (default)
     */
    @Override
    public Integer visitNil(BrainfuckParser.NilContext ctx) {
        return tape.get(index) != null ? tape.get(index) : 0;
    }
}
