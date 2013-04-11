#include "MainWindow.h"



MainWindow::MainWindow()  {
    //We need a scene and a view to do graphics in QT
    
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
    QRadioButton *OutofPlaceButton = new QRadioButton("OutofPlace Heuristic", this);
    QRadioButton *ManhattanButton = new QRadioButton("Manhattan Heuristic", this);
    
  
    QFormLayout *formLayout = new QFormLayout;
    QHBoxLayout *HBoxLayout = new QHBoxLayout;
    QHBoxLayout *HBoxLayout2 = new QHBoxLayout;
    QVBoxLayout *VBoxLayout = new QVBoxLayout;
    HBoxLayout->addWidget(startButton);
    HBoxLayout->addWidget(quitButton);
    HBoxLayout2->addWidget(OutofPlaceButton);
    HBoxLayout2->addWidget(ManhattanButton);
    VBoxLayout->addLayout(HBoxLayout);
    VBoxLayout->addLayout(formLayout);
    VBoxLayout->addLayout(HBoxLayout2);
    VBoxLayout->addWidget(view);
    VBoxLayout->addWidget(botview);
    formLayout->addRow(sizeLabel, lineEdit1);
    formLayout->addRow(turnLabel, lineEdit2);
    formLayout->addRow(seedLabel, lineEdit3);
    window->setLayout(VBoxLayout);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(quit()));
    connect(startButton, SIGNAL(clicked()), this, SLOT(start()));
    
       
}

void MainWindow::show() {

    //This is how we get our view displayed.
    window->show();
    
}

void MainWindow::quit() {

    exit(1);
}

void MainWindow::moveTile(GUITile *guitile){
	//moves tiles.
	int temp = 0;
	int tempzero = 0;
	stringstream ss;
    	string s;
	int dim = static_cast<int>(sqrt(size_));
	int neighbors[4];
	for (int a = 0; a <size_; a++)
	{
		if(tilevector[a]->tile_ == 0)
		{ tempzero = a; 
		break;}
	}
	for (int i = 0; i < size_; i++)
	{
		if(tilevector[i]->tile_  == guitile->tile_)
		{		temp = i;
		break;}
	}
	if (temp >= dim)
	{
		neighbors[0] = tilevector[temp-dim]->tile_;
	}
	else{neighbors[0] = -1;}
	if ((temp+1)%dim != 0)
	{
		neighbors[1] = tilevector[temp+1]->tile_;
	}
	else{neighbors[1] = -1;}
	if (temp%dim != 0)
	{
		neighbors[2] = tilevector[temp-1]->tile_;
	}
	else{neighbors[2] = -1;}
	if (temp < (size_ - dim))
	{
		neighbors[3] = tilevector[temp+dim]->tile_;
	}
	else{neighbors[3] = -1;}
	for (int j = 0; j < 4; j++)
	{
		if(neighbors[j] == 0)
		{
			//swap(tilevector[tempzero],tilevector[temp]);
			
			tilevector[tempzero]->tile_ = guitile->tile_;
			tilevector[temp]->tile_ = 0;
			QPointF p((tilevector[tempzero]->x),(tilevector[tempzero]->y));
			QPointF p2((tilevector[temp]->x),(tilevector[temp]->y));
			//QPointF p3((tilevector[tempzero]->x + 25),(25 +tilevector[tempzero]->y));
			//QPointF p4((tilevector[temp]->x + 25),(tilevector[temp]->y + 25));
			QRectF r( tilevector[temp]->rect() );
			QRectF r2( tilevector[tempzero]->rect() );
   			r.moveTo(p);
   			//tilevector[temp]->text->setPos(p3);
   			//tilevector[tempzero]->text->setPos(p4);
   			r2.moveTo(p2);
   			
   			
			ss << tilevector[tempzero]->tile_;
			s = ss.str();
			tilevector[tempzero]->text->setText(s.c_str());
			tilevector[temp]->text->setText("");
			
			//tilevector[tempzero]->setPos(p2);
    			//tilevector[temp]->setPos(p);
			
			break;
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
		tilevector.push_back(new GUITile(x,y,50,50,b->getTiles()[i],this));
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

