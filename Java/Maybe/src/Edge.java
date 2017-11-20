public class Edge extends AbstractPiece {

    Sticker S1;
    Sticker S2;

    Edge(Sticker S1,Sticker S2){
        super(2); //Edges always have 2 Stickers
        this.S1=S1;
        this.S2=S2;
    }

} 