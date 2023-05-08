import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

public class IntExp extends IntExpBaseVisitor<Double> {
    private final Map<String, Double> vars = new HashMap<>();

    @Override
    public Double visitMain(IntExpParser.MainContext ctx) {
        return visit(ctx.begin());
    }

    @Override
    public Double visitBegin(IntExpParser.BeginContext ctx) {
        visit(ctx.dec());
        return visit(ctx.exp());
    }

    @Override
    public Double visitDec(IntExpParser.DecContext ctx) {
        for(int i = 0; i < ctx.exp().size(); i++)
        {
            String var = ctx.ALF(i).getText();
            Double value = visit(ctx.exp(i));
            vars.put(var, value);
        }
        return null;
    }

    @Override
    public Double visitFloat(IntExpParser.FloatContext ctx) {
        return Double.parseDouble(ctx.FLOAT().getText());
    }

    @Override
    public Double visitAlf(IntExpParser.AlfContext ctx) {
        // Take the value from the Map
        Double value = vars.get(ctx.ALF().getText());
        // Return the value if it's not null, otherwise 0
        return Objects.requireNonNullElse(value, 0.0);
    }

    @Override
    public Double visitMultDiviModu(IntExpParser.MultDiviModuContext ctx) {
        if(ctx.op.getType() == IntExpParser.MULT)
            return visit(ctx.exp(0)) * visit(ctx.exp(1));
        else if(ctx.op.getType() == IntExpParser.DIVI)
            return visit(ctx.exp(0)) / visit(ctx.exp(1));
        else if(ctx.op.getType() == IntExpParser.MODU)
            return visit(ctx.exp(0)) % visit(ctx.exp(1));
        else
            return null;
    }

    @Override
    public Double visitPlusSubt(IntExpParser.PlusSubtContext ctx) {
        if(ctx.op.getType() == IntExpParser.PLUS)
            return visit(ctx.exp(0)) + visit(ctx.exp(1));
        else if(ctx.op.getType() == IntExpParser.SUBT)
            return visit(ctx.exp(0)) - visit(ctx.exp(1));
        else
            return null;
    }

    @Override
    public Double visitPote(IntExpParser.PoteContext ctx) {
        return Math.pow(visit(ctx.exp(0)), visit(ctx.exp(1)));
    }

    @Override
    public Double visitExpCont(IntExpParser.ExpContContext ctx) {
        return visit(ctx.exp());
    }
}
