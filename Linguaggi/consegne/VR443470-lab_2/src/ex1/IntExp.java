package ex1;

public class IntExp extends IntExpBaseVisitor<Integer> {
    @Override
    public Integer visitMain(IntExpParser.MainContext ctx) {
        return visit(ctx.exp());
    }

    @Override
    public Integer visitPlus(IntExpParser.PlusContext ctx) {
        int left = visit(ctx.exp(0));
        int right = visit(ctx.exp(1));
        return left + right;
    }

    @Override
    public Integer visitMul(IntExpParser.MulContext ctx) {
        int left = visit(ctx.exp(0));
        int right = visit(ctx.exp(1));
        return left * right;
    }

    @Override
    public Integer visitSub(IntExpParser.SubContext ctx) {
        int left = visit(ctx.exp(0));
        int right = visit(ctx.exp(1));
        return left - right;
    }

    @Override
    public Integer visitDiv(IntExpParser.DivContext ctx) {
        int left = visit(ctx.exp(0));
        int right = visit(ctx.exp(1));
        return left / right;
    }

    @Override
    public Integer visitMod(IntExpParser.ModContext ctx) {
        int left = visit(ctx.exp(0));
        int right = visit(ctx.exp(1));
        return left % right;
    }

    @Override
    public Integer visitNat(IntExpParser.NatContext ctx) {
        return Integer.parseInt(ctx.NAT().getText());
    }
}
