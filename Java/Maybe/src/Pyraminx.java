public class Pyraminx {

    Tip T1;
    Tip T2;
    Tip T3;
    Tip T4;
    Center C1;
    Center C2;
    Center C3;
    Center C4;
    Edge E1;
    Edge E2;
    Edge E3;
    Edge E4;
    Edge E5;
    Edge E6;
    String Solution;

    Pyraminx(Tip T1,Tip T2,Tip T3,Tip T4,Center C1,Center C2,Center C3,Center C4,Edge E1,Edge E2,Edge E3,Edge E4,Edge E5,Edge E6,String Solution){
        this.T1=T1;
        this.T2=T2;
        this.T3=T3;
        this.T4=T4;
        this.C1=C1;
        this.C2=C2;
        this.C3=C3;
        this.C4=C4;
        this.E1=E1;
        this.E2=E2;
        this.E3=E3;
        this.E4=E4;
        this.E5=E5;
        this.E6=E6;
        this.Solution=Solution;
    }

    /*
    // Returns a new pyraminx instead of a mutated one
    Pyraminx Ro(){
        return new Pyraminx(T1,new Tip(T2.S3,T2.S1,T2.S2),T3,T4,C1,new Center(C2.S3,C2.S1,C2.S2),C3,C4,E1,new Edge(E5.S2,E5.S1),
                new Edge(E2.S2,E2.S1),E4,new Edge(E3.S1,E3.S2),E6,Solution+" R");
    }
    */

    //***Note***
    //All prime moves (EX R', U', etc.) are noted with a single letter. The letter used is the letter to the left of its non prime character
    // on a QWERTY keyboard

    Pyraminx R(){
        //Order does matter in move functions
        //Otherwise, the pieces can get mixed up with their changed parts and not their original pieces
        //E2O stands for original, it is a place holder because E2 is later modified

        Edge E2O = E2;

        T2=new Tip(T2.S3,T2.S1,T2.S2);
        C2=new Center(C2.S3,C2.S1,C2.S2);
        E2=new Edge(E5.S2,E5.S1);
        E5=E3;
        E3=new Edge(E2O.S2,E2O.S1);
        Solution=Solution+"R";
        return this;
    }

    Pyraminx E(){
        //F==R'==R prime

        Edge E2O = E2;

        T2=new Tip(T2.S2,T2.S3,T2.S1);
        C2=new Center(C2.S2,C2.S3,C2.S1);
        E2=new Edge(E3.S2,E3.S1);
        E3=E5;
        E5=new Edge(E2O.S2,E2O.S1);
        Solution+="E";

        return this;
    }

    Pyraminx L(){

        Edge E3O = E3;

        T3=new Tip(T3.S3,T3.S1,T3.S2);
        C3=new Center(C3.S3,C3.S1,C3.S2);
        E3=new Edge(E6.S2,E6.S1);
        E6=E1;
        E1=new Edge(E3O.S2,E3O.S1);
        Solution+="L";

        return this;
    }

    Pyraminx K(){

        Edge E3O = E3;

        T3=new Tip(T3.S2,T3.S3,T3.S1);
        C3=new Center(C3.S2,C3.S3,C3.S1);
        E1=E6;
        E3=new Edge(E1.S2,E1.S1);
        E6=new Edge(E3O.S2,E3O.S1);
        Solution+="K";

        return this;
    }

    Pyraminx U(){

        Edge E4O = E4;

        T4=new Tip(T4.S3,T4.S1,T4.S2);
        C4=new Center(C4.S3,C4.S1,C4.S2);
        E4=E6;
        E6=E5;
        E5=E4O;
        Solution+="U";

        return this;
    }

    Pyraminx Y(){
        //U prime==U'==J

        Edge E4O = E4;

        T4=new Tip(T4.S2,T4.S3,T4.S1);
        C4=new Center(C4.S2,C4.S3,C4.S1);
        E4=E5;
        E5=E6;
        E6=E4O;
        Solution+="Y";

        return this;
    }

    Pyraminx B(){

        Edge E1O = E1;

        T1=new Tip(T1.S3,T1.S1,T3.S2);
        C1=new Center(C1.S3,C1.S1,C1.S2);
        E1=new Edge(E4.S2,E4.S1);
        E4=E2;
        E2=new Edge(E1O.S2,E1O.S1);
        Solution+="B";

        return this;
    }

    Pyraminx V(){

        Edge E1O = E1;

        T1=new Tip(T1.S2,T1.S3,T1.S1);
        C1=new Center(C1.S2,C1.S3,C1.S1);
        E1=new Edge(E2.S2,E2.S1);
        E2=E4;
        E4=new Edge(E1O.S2,E1O.S1);

        return this;
    }

} 