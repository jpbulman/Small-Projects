public class Main {

    //Yellow bottom, Green front, Red left, Blue right

    //Tips start at the back and go clockwise, the 4th is the top one
    //T1 has S1 as the bottom face, S2 as right face, and S3 as left face
    //T2 has S1 bottom, S2 front, S3 right
    //T3 has S1 bottom, S2 left, S3 front
    //T4 has S1 right, S2 front, S3 left

    //Centers start at the back and go clockwise around the bottom (4th is on top)
    //C1 has S1 bottom, S2 right, S3 left
    //C2 has S1 bottom, S2 front, S3 right
    //C3 has S1 bottom, S2 left, S3 front
    //C4 has S1 right, S2 front, S3 left

    //Edges start at the back left (or back in the top layer) and go clockwise
    //Edges 1-3 have S1 on the bottom face and their S2 on whatever remaining face is left
    //Edges 4-6 have S1 on the right side (from a constant perspective) and S2 on the left
    //EX: E4 solved is B R
    //E1 solved is Y R

    static  Tip t1 = new Tip(new Sticker("Y"),new Sticker("B"),new Sticker("R"));
    static  Tip t2 = new Tip(new Sticker("Y"),new Sticker("G"),new Sticker("B"));
    static Tip t3 = new Tip(new Sticker("Y"),new Sticker("R"),new Sticker("G"));
    static Tip t4 = new Tip(new Sticker("B"),new Sticker("G"),new Sticker("R"));

    static Center c1 = new Center(new Sticker("Y"),new Sticker("B"),new Sticker("R"));
    static  Center c2 = new Center(new Sticker("Y"),new Sticker("G"),new Sticker("B"));
    static Center c3 = new Center(new Sticker("Y"),new Sticker("R"),new Sticker("G"));
    static Center c4 = new Center(new Sticker("B"),new Sticker("G"),new Sticker("R"));

    static Edge e1 = new Edge(new Sticker("Y"),new Sticker("R"));
    static Edge e2 = new Edge(new Sticker("Y"),new Sticker("B"));
    static Edge e3 = new Edge(new Sticker("Y"),new Sticker("G"));
    static Edge e4 = new Edge(new Sticker("B"),new Sticker("R"));
    static Edge e5 = new Edge(new Sticker("G"),new Sticker("B"));
    static Edge e6 = new Edge(new Sticker("R"),new Sticker("G"));

    static Pyraminx Solved = new Pyraminx(t1,t2,t3,t4,c1,c2,c3,c4,e1,e2,e3,e4,e5,e6,"");

    public static String Solve(Pyraminx pyra){

        return "";
    }

    public static void main(String[] args){

        System.out.println(Solved.isSolved());

    }

} 