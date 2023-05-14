package value;

import java.util.List;

public class ArrValue extends ExpValue<List<ExpValue<?>>> {
    public ArrValue(List<ExpValue<?>> value) {
        super(value);
    }

    public void memory(int index, ExpValue<?> exp) {
        if (index >= toJavaValue().size())
            for (int i = toJavaValue().size(); i <= index; ++i)
                toJavaValue().add(null);
        toJavaValue().set(index, exp);
    }

    public ExpValue<?> get(int index) {
        return toJavaValue().get(index);
    }
}