import java.util.ArrayList;

import org.apache.commons.lang3.StringEscapeUtils;
import value.*;

public class IntImp extends ImpBaseVisitor<Value> {

    private final Conf conf;

    public IntImp(Conf conf) {
        this.conf = conf;
    }

    private ComValue visitCom(ImpParser.ComContext ctx) {
        return (ComValue) visit(ctx);
    }

    private ExpValue<?> visitExp(ImpParser.ExpContext ctx) {
        return (ExpValue<?>) visit(ctx);
    }

    private boolean visitBoolExp(ImpParser.ExpContext ctx) {
        try {
            return ((BoolValue) visitExp(ctx)).toJavaValue();
        } catch (ClassCastException e) {
            System.err.println("Type mismatch exception!");
            System.err.println("@" + ctx.start.getLine() + ":" + ctx.start.getCharPositionInLine());
            System.err.println(">>>>>>>>>>>>>>>>>>>>>>>>");
            System.err.println(ctx.getText());
            System.err.println("<<<<<<<<<<<<<<<<<<<<<<<<");
            System.err.println("> Boolean expression expected.");
            System.exit(1);
        }

        return false; // unreachable code
    }

    private int visitNatExp(ImpParser.ExpContext ctx) {
        try {
            return ((NatValue) visitExp(ctx)).toJavaValue();
        } catch (ClassCastException e) {
            System.err.println("Type mismatch exception!");
            System.err.println("@" + ctx.start.getLine() + ":" + ctx.start.getCharPositionInLine());
            System.err.println(">>>>>>>>>>>>>>>>>>>>>>>>");
            System.err.println(ctx.getText());
            System.err.println("<<<<<<<<<<<<<<<<<<<<<<<<");
            System.err.println("> Natural expression expected.");
            System.exit(1);
        }

        return 0; // unreachable code
    }

    private String visitStrExp(ImpParser.ExpContext ctx) {
        try {
            return ((StrValue) visit(ctx)).toJavaValue();
        } catch (ClassCastException e) {
            System.err.println("Type mismatch exception!");
            System.err.println("@" + ctx.start.getLine() + ":" + ctx.start.getCharPositionInLine());
            System.err.println(">>>>>>>>>>>>>>>>>>>>>>>>");
            System.err.println(ctx.getText());
            System.err.println("<<<<<<<<<<<<<<<<<<<<<<<<");
            System.err.println("> String expression expected.");
            System.exit(1);
        }

        return null; // unreachable code
    }

    @Override
    public ComValue visitProg(ImpParser.ProgContext ctx) {
        return visitCom(ctx.com());
    }

    @Override
    public ComValue visitIf(ImpParser.IfContext ctx) {
        return visitBoolExp(ctx.exp())
                ? visitCom(ctx.com(0))
                : visitCom(ctx.com(1));
    }

    @Override
    public ComValue visitAssign(ImpParser.AssignContext ctx) {
        String id = ctx.ID().getText();
        ExpValue<?> v = visitExp(ctx.exp());

        conf.update(id, v);

        return ComValue.INSTANCE;
    }

    @Override
    public ComValue visitSkip(ImpParser.SkipContext ctx) {
        return ComValue.INSTANCE;
    }

    @Override
    public ComValue visitSeq(ImpParser.SeqContext ctx) {
        visitCom(ctx.com(0));
        return visitCom(ctx.com(1));
    }

    @Override
    public ComValue visitWhile(ImpParser.WhileContext ctx) {
        if (!visitBoolExp(ctx.exp()))
            return ComValue.INSTANCE;

        visitCom(ctx.com());

        return visitWhile(ctx);
    }

    @Override
    public ComValue visitOut(ImpParser.OutContext ctx) {
        System.out.println(visitStrExp(ctx.exp()));
        return ComValue.INSTANCE;
    }

    @Override
    public NatValue visitNat(ImpParser.NatContext ctx) {
        return new NatValue(Integer.parseInt(ctx.NAT().getText()));
    }

    @Override
    public BoolValue visitEqExp(ImpParser.EqExpContext ctx) {
        ExpValue<?> left = visitExp(ctx.exp(0));
        ExpValue<?> right = visitExp(ctx.exp(1));

        return switch (ctx.op.getType()) {
            case ImpParser.EQQ -> new BoolValue(left.equals(right));
            case ImpParser.NEQ -> new BoolValue(!left.equals(right));
            default -> null; // unreachable code
        };
    }

    @Override
    public ExpValue<?> visitId(ImpParser.IdContext ctx) {
        String id = ctx.ID().getText();

        if (!conf.contains(id)) {
            System.err.println("Variable " + id + " used but never instantiated");
            System.err.println("@" + ctx.start.getLine() + ":" + ctx.start.getCharPositionInLine());

            System.exit(1);
        }

        return conf.get(id);
    }

    @Override
    public BoolValue visitBool(ImpParser.BoolContext ctx) {
        return new BoolValue(Boolean.parseBoolean(ctx.BOOL().getText()));
    }

    @Override
    public ExpValue<?> visitParExp(ImpParser.ParExpContext ctx) {
        return visitExp(ctx.exp());
    }

    @Override
    public NatValue visitPow(ImpParser.PowContext ctx) {
        int base = visitNatExp(ctx.exp(0));
        int exp = visitNatExp(ctx.exp(1));
        return new NatValue((int) Math.pow(base, exp));
    }

    @Override
    public NatValue visitPlusMinus(ImpParser.PlusMinusContext ctx) {
        int left = visitNatExp(ctx.exp(0));
        int right = visitNatExp(ctx.exp(1));

        return switch (ctx.op.getType()) {
            case ImpParser.PLUS  -> new NatValue(left + right);
            case ImpParser.MINUS -> new NatValue(Math.max(left - right, 0));
            default -> null; // unreachable code
        };
    }

    @Override
    public NatValue visitDivMulMod(ImpParser.DivMulModContext ctx) {
        int left = visitNatExp(ctx.exp(0));
        int right = visitNatExp(ctx.exp(1));

        return switch (ctx.op.getType()) {
            case ImpParser.DIV -> new NatValue(left / right);
            case ImpParser.MUL -> new NatValue(left * right);
            case ImpParser.MOD -> new NatValue(left % right);
            default -> null; // unreachable code
        };
    }

    @Override
    public BoolValue visitCmpExp(ImpParser.CmpExpContext ctx) {
        int left = visitNatExp(ctx.exp(0));
        int right = visitNatExp(ctx.exp(1));

        return switch (ctx.op.getType()) {
            case ImpParser.LT  -> new BoolValue(left < right);
            case ImpParser.LEQ -> new BoolValue(left <= right);
            case ImpParser.GEQ -> new BoolValue(left >= right);
            case ImpParser.GT  -> new BoolValue(left > right);
            default -> null; // unreachable code
        };
    }

    @Override
    public ExpValue<?> visitAndOrConcExp(ImpParser.AndOrConcExpContext ctx) {
        if (ctx.op.getType() == ImpParser.CONC)
            return new StrValue(visitStrExp(ctx.exp(0)) + visitStrExp(ctx.exp(1)));
        else {
            boolean left = visitBoolExp(ctx.exp(0));
            boolean right = visitBoolExp(ctx.exp(1));

            return switch (ctx.op.getType()) {
                case ImpParser.AND -> new BoolValue(left && right);
                case ImpParser.OR  -> new BoolValue(left || right);
                default -> null; // unreachable code
            };
        }
    }

    @Override
    public BoolValue visitNot(ImpParser.NotContext ctx) {
        return new BoolValue(!visitBoolExp(ctx.exp()));
    }

    @Override
    public Value visitString(ImpParser.StringContext ctx) {
        return new StrValue(StringEscapeUtils.unescapeJava(ctx.STRING().getText().substring(1, ctx.STRING().getText().length() - 1)));
    }

    @Override
    public Value visitToStr(ImpParser.ToStrContext ctx) {
        return new StrValue(visitExp(ctx.exp()).toString());
    }

    @Override
    public ComValue visitArray(ImpParser.ArrayContext ctx) {
        String id = ctx.ID().getText();

        if (!conf.contains(id) || !(conf.get(id) instanceof ArrValue))
            conf.update(id, new ArrValue(new ArrayList<>()));

        ((ArrValue) conf.get(id)).memory(visitNatExp(ctx.exp(0)), visitExp(ctx.exp(1)));

        return ComValue.INSTANCE;
    }

    @Override
    public ExpValue<?> visitAccess(ImpParser.AccessContext ctx) {
        String id = ctx.ID().getText();
        int index = visitNatExp(ctx.exp());

        if (!conf.contains(id)) {
            System.err.println("Array '" + id + "' never assigned.");
            System.exit(1);
        }
        if (!(conf.get(id) instanceof ArrValue)) {
            System.err.println("Value '" + id + "' is not an array type.");
            System.exit(1);
        }
        if (((ArrValue) conf.get(id)).get(index) == null) {
            System.err.println("Value '" + id + "[" + index + "]" + "' never assigned.");
            System.exit(1);
        }
        return ((ArrValue) conf.get(id)).get(index);
    }
}