#include "MainWindow.h"



MainWindow::MainWindow()  {
    //We need a scene and a view to do graphics in QT
    count = 0;
    scene = new QGraphicsScene();
    view = new QGraphicsView( scene );
    botscene = new QGraphicsScene();
    botview = new QGraphicsView( botscene );
    view->setFixedSize( WINDOW_MAX_X*2, WINDOW_MAX_Y*2 );
    window = new QWidget;
    QValidator *validator1 = new QIntValidator(this);
    QValidator *validator2 = new QIntValidator(this);
    QValidator *validator3 = new QIntValidator(this);
    lineEdit1 = new QLineEdit(this);
    lineEdit2 = new QLineEdit(this);
    lineEdit3 = new QLineEdit(this);
    lineEdit1->setValidator(validator1);
    lineEdit2->setValidator(validator2);
    lineEdit3->setValidator(validator3);
    QLabel *sizeLabel = new QLabel("Size",this);
    QLabel *turnLabel = new QLabel("Amount of Randomization",this);
    QLabel *seedLabel = new QLabel("Seed",this);
    QPushButton *startButton = new QPushButton("&Start",this);
    QPushButton *quitButton = new QPushButton("&Quit", this);
    OutofPlaceButton = new QRadioButton("OutofPlace Heuristic", this);
    ManhattanButton = new QRadioButton("Manhattan Heuristic", this);
    QPushButton *AlgButton = new QPushButton("&Cheat!", this);
    
  
    QFormLayout *formLayout = new QFormLayout;
    QHBoxLayout *HBoxLayout = new QHBoxLayout;
    QHBoxLayout *HBoxLayout2 = new QHBoxLayout;
    QHBoxLayout *HBoxLayout3 = new QHBoxLayout;
    QVBoxLayout *VBoxLayout = new QVBoxLayout;
    HBoxLayout->addWidget(startButton);
    HBoxLayout->addWidget(quitButton);
    HBoxLayout2->addWidget(OutofPlaceButton);
    HBoxLayout2->addWidget(ManhattanButton);
    HBoxLayout3->addWidget(AlgButton);
    VBoxLayout->addLayout(HBoxLayout);
    VBoxLayout->addLayout(formLayout);
    VBoxLayout->addLayout(HBoxLayout2);
    VBoxLayout->addWidget(view);
    VBoxLayout->addLayout(HBoxLayout3);
    HBoxLayout3->addWidget(botview);
    formLayout->addRow(sizeLabel, lineEdit1);
    formLayout->addRow(turnLabel, lineEdit2);
    formLayout->addRow(seedLabel, lineEdit3);
    window->setLayout(VBoxLayout);
    timer = new QTimer(this);
    timer->setInterval(5);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(quit()));
    connect(startButton, SIGNAL(clicked()), this, SLOT(start()));
    connect(AlgButton, SIGNAL(clicked()), this, SLOT(displayAlg()));
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
       
}



void MainWindow::show() {

    //This is how we get our view displayed.
    window->show();
    
}

void MainWindow::quit() {

    exit(1);
}

void MainWindow::displayAlg() {
	if(tilevector.size() < 5)
	{
		botscene->clear();
    		QGraphicsSimpleTextItem *error5 = new QGraphicsSimpleTextItem("You must first generate a Board.");
    		botscene->addItem(error5);
    		return;
    	}
    	else
    	{	
	stringstream ss;
	string s;
	PuzzleHeuristic *pm;
	if(OutofPlaceButton->isChecked())
	{
		pm = new OutofPlaceHeuristic();
	}
	else if(ManhattanButton->isChecked())
	{
		pm = new ManhattanHeuristic();
	}
	else{
		botscene->clear();
    		QGraphicsSimpleTextItem *error4 = new QGraphicsSimpleTextItem("You must check a box!");
    		botscene->addItem(error4);
    		return;
	}
	PuzzleSolver solver(*b);
   	int count = solver.run(pm);
   	for(int j = (count-1); j >=0; j--)
   	{
   		ss << solver.getSequence().at(j) << " ";
   	}
   	s = ss.str();
   	botscene->clear();
    	QGraphicsSimpleTextItem *Alg = new QGraphicsSimpleTextItem(s.c_str());
    	botscene->addItem(Alg);
    	}

}

void MainWindow::handleTimer() {
	count++;
	if(count == 51)
	{
		timer->stop();
		count = 0;
		if(b->solved())
 		{
 			for(unsigned int i = 0; i < tilevector.size(); i++)
   			{
 				delete tilevector[i];
   			}
   		tilevector.clear();
 		scene->clear();
 		botscene->clear();
    		QGraphicsSimpleTextItem *victory = new QGraphicsSimpleTextItem("You Win!");
    		botscene->addItem(victory);
    		}
		return;
	}
	
	QRectF r( tilevector[temp]->rect() );
	QRectF r2( tilevector[tempzero]->rect());
	tilevector[temp]->y -=velocityY;
	tilevector[temp]->x -=velocityX;
	tilevector[tempzero]->y += velocityY;
	tilevector[tempzero]->x += velocityX;
	
	QPointF p((tilevector[temp]->x),(tilevector[temp]->y));
	QPointF p2((tilevector[tempzero]->x),(tilevector[tempzero]->y));
	r.moveTo(p);
	r2.moveTo(p2);
	tilevector[temp]->setRect( r );
	tilevector[tempzero]->setRect( r2 );
	
	QPointF p3((tilevector[tempzero]->x+25),(tilevector[tempzero]->y+25));
	QPointF p4((tilevector[temp]->x+25),(tilevector[temp]->y+25));
	tilevector[temp]->text->setPos(p4);
   	tilevector[tempzero]->text->setPos(p3);
	
}

void MainWindow::moveTile(GUITile *guitile){
	//moves tiles.
	if(timer->isActive())
	{}
	else{
	temp = 0;
	tempzero = 0;
	stringstream ss;
    	string s;
	int dim = static_cast<int>(sqrt(size_));
	int neighbors[4];
	for (int a = 0; a <size_; a++)
	{
		if(b->getTiles()[a] == 0)
		{ tempzero = a; 
		break;}
	}
	for (int i = 0; i < size_; i++)
	{
		if(b->getTiles()[i]  == guitile->tile_)
		{		temp = i;
		break;}
	}
	if (temp >= dim)
	{
		neighbors[0] = b->getTiles()[temp-dim];
	}
	else{neighbors[0] = -1;}
	if ((temp+1)%dim != 0)
	{
		neighbors[1] = b->getTiles()[temp+1];
	}
	else{neighbors[1] = -1;}
	if (temp%dim != 0)
	{
		neighbors[2] = b->getTiles()[temp-1];
	}
	else{neighbors[2] = -1;}
	if (temp < (size_ - dim))
	{
		neighbors[3] = b->getTiles()[temp+dim];
	}
	else{neighbors[3] = -1;}
	for (int j = 0; j < 4; j++)
	{
		if(neighbors[j] == 0)
		{
			b->getTiles()[tempzero] = guitile->tile_;
			b->getTiles()[temp] = 0;
			
			if(j==0)
			{
				//tilevector[temp]->y -=50;
				//tilevector[tempzero]->y +=50;
				velocityX = 0;
				velocityY = -1;
				
				/*QPointF p((tilevector[temp]->x),(tilevector[temp]->y));
				QPointF p2((tilevector[tempzero]->x),(tilevector[tempzero]->y));
				r.moveTo(p);
				r2.moveTo(p2);
				tilevector[temp]->setRect( r );
				tilevector[tempzero]->setRect( r2 );
				
				QPointF p3((tilevector[tempzero]->x+25),(tilevector[tempzero]->y+25));
				QPointF p4((tilevector[temp]->x+25),(tilevector[temp]->y+25));
				tilevector[temp]->text->setPos(p4);
   				tilevector[tempzero]->text->setPos(p3);*/
   				timer->start();
				
				swap(tilevector[temp],tilevector[tempzero]);
			}
			if(j==1)
			{
				//tilevector[temp]->x +=50;
				//tilevector[tempzero]->x -=50;
				velocityX = 1;
				velocityY = 0;
				
				/*QPointF p((tilevector[temp]->x),(tilevector[temp]->y));
				QPointF p2((tilevector[tempzero]->x),(tilevector[tempzero]->y));
				r.moveTo(p);
				r2.moveTo(p2);
				tilevector[temp]->setRect( r );
				tilevector[tempzero]->setRect( r2 );
				
				QPointF p3((tilevector[tempzero]->x+25),(tilevector[tempzero]->y+25));
				QPointF p4((tilevector[temp]->x+25),(tilevector[temp]->y+25));
				tilevector[temp]->text->setPos(p4);
   				tilevector[tempzero]->text->setPos(p3);*/
   				timer->start();
				
				swap(tilevector[temp],tilevector[tempzero]);
			}
			if(j==2)
			{
				//tilevector[temp]->x -=50;
				//tilevector[tempzero]->x +=50;
				velocityX = -1;
				velocityY = 0;
				
				/*QPointF p((tilevector[temp]->x),(tilevector[temp]->y));
				QPointF p2((tilevector[tempzero]->x),(tilevector[tempzero]->y));
				r.moveTo(p);
				r2.moveTo(p2);
				tilevector[temp]->setRect( r );
				tilevector[tempzero]->setRect( r2 );
				
				QPointF p3((tilevector[tempzero]->x+25),(tilevector[tempzero]->y+25));
				QPointF p4((tilevector[temp]->x+25),(tilevector[temp]->y+25));
				tilevector[temp]->text->setPos(p4);
   				tilevector[tempzero]->text->setPos(p3);*/
   				timer->start();
				
				swap(tilevector[temp],tilevector[tempzero]);
			}
			if(j==3)
			{
				//tilevector[temp]->y +=50;
				//tilevector[tempzero]->y -=50;
				velocityX = 0;
				velocityY = 1;
				
				/*QPointF p((tilevector[temp]->x),(tilevector[temp]->y));
				QPointF p2((tilevector[tempzero]->x),(tilevector[tempzero]->y));
				r.moveTo(p);
				r2.moveTo(p2);
				tilevector[temp]->setRect( r );
				tilevector[tempzero]->setRect( r2 );
				
				QPointF p3((tilevector[tempzero]->x+25),(tilevector[tempzero]->y+25));
				QPointF p4((tilevector[temp]->x+25),(tilevector[temp]->y+25));
				tilevector[temp]->text->setPos(p4);
   				tilevector[tempzero]->text->setPos(p3);*/
				timer->start();
				swap(tilevector[temp],tilevector[tempzero]);
			}
			
			break;
		}
	}
	}
}

void MainWindow::start(){
    //checks to see if three values are inputted
    if((lineEdit1->text().isEmpty())||(lineEdit2->text().isEmpty())||(lineEdit3->text().isEmpty()))
    {
    	botscene->clear();
    	QGraphicsSimpleTextItem *error = new QGraphicsSimpleTextItem("You must enter values for all three fields.");
    	botscene->addItem(error);
    	return;
    }
    else{
    int x = 0;
    int y = 0;
    int init_ = 0;
    int seed_ = 0;
    stringstream ss;
    string s;
    botscene->clear();
    //checks to see if the size input is valid
    if(!(lineEdit1->text().toInt() == 9||lineEdit1->text().toInt() == 16))
    {
        QGraphicsSimpleTextItem *error1 = new QGraphicsSimpleTextItem("You must enter either 9 or 16 as the size");
    	botscene->addItem(error1);
    	return;
    }
    else
    {
        size_ = lineEdit1->text().toInt();
    }
    //checks to see if the initial value input is valid
    if(lineEdit2->text().toInt()<0)
    {
        QGraphicsSimpleTextItem *error2 = new QGraphicsSimpleTextItem("You must enter a positive number");
    	botscene->addItem(error2);
    	return;
    }
    else{
    init_ = lineEdit2->text().toInt();}
    //checks to see if the seed input is valid
    if(lineEdit3->text().toInt()<0){
        QGraphicsSimpleTextItem *error3 = new QGraphicsSimpleTextItem("You must enter a positive number");
    	botscene->addItem(error3);
    	return;
    	}
    else{
    seed_ = lineEdit3->text().toInt();}
    int dim = static_cast<int>(sqrt(size_));
    for(unsigned int i = 0; i < tilevector.size(); i++)
    {
 	delete tilevector[i];
    }
    tilevector.clear();
    scene->clear();
    
    b = new Board(size_, init_, seed_);
    for (int i = 0; i < size_; i++)
    {
    	x+= 50;
    	ss << b->getTiles()[i];
    	s = ss.str();

	if(i%dim == 0){
	y+=50;
	x-= 50*dim;
	}
	if(b->getTiles()[i] == 0)
	{
		tilevector.push_back(new GUITile(x,y,0,0,b->getTiles()[i],this));
		tilevector[i]->text = new QGraphicsSimpleTextItem("");
		tilevector[i]->text->setPos(x+25,y+25);
		scene->addItem( tilevector[i] );
		scene->addItem( tilevector[i]->text);
	}
	else{
		tilevector.push_back(new GUITile(x,y,50,50,b->getTiles()[i],this));
		tilevector[i]->text = new QGraphicsSimpleTextItem(s.c_str());
		tilevector[i]->text->setPos(x+25,y+25);
		scene->addItem( tilevector[i] );
		scene->addItem( tilevector[i]->text);
	}
	ss.str("");
    }
    }
    
}

MainWindow::~MainWindow()
{
    delete scene;
    delete view;
    delete window;
}

