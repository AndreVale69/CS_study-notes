package ex1;

import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;

import java.io.IOException;
import java.io.InputStream;

public class Main {
    public static void main(String[] args) throws IOException {
        ClassLoader classLoader = Thread.currentThread().getContextClassLoader();
        InputStream inputStream = classLoader.getResourceAsStream(args[0]);
        CharStream charStream = CharStreams.fromStream(inputStream);

        IntExpLexer intExpLexer = new IntExpLexer(charStream);
        CommonTokenStream commonTokenStream = new CommonTokenStream(intExpLexer);
        IntExpParser intExpParser = new IntExpParser(commonTokenStream);

        ParseTree tree = intExpParser.main();

        IntExp intExp = new IntExp();
        System.out.println(intExp.visit(tree));
    }
}
