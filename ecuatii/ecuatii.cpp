#include "ecuatii.h"
#include <string>

ecuatii::ecuatii(Repository& _repo, QWidget *parent)
	: QMainWindow(parent), repo{_repo}
{
	ui.setupUi(this);
	this->populate();
	QObject::connect(ui.computeButton, &QPushButton::clicked, this, &ecuatii::computeValues);
	//QObject::connect(ui.equationList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(editFct(QListWidgetItem*)));
	QObject::connect(ui.equationList, &QListWidget::itemDoubleClicked, this,&ecuatii::editFct);
	QObject::connect(ui.alineEdit, &QLineEdit::returnPressed, this, &ecuatii::edita);
	QObject::connect(ui.blineEdit, &QLineEdit::returnPressed, this, &ecuatii::editb);
	QObject::connect(ui.clineEdit, &QLineEdit::returnPressed, this, &ecuatii::editc);

}

void ecuatii::populate()
{
	this->ui.equationList->clear();
	for (auto x : this->repo.getAll())
	{
		std::string u = "";
		std::string a = std::to_string(x.getA());
		std::string b = std::to_string(x.getB());
		std::string c = std::to_string(x.getC());
		u += a + "*x^2 + " + b + "*x + " + c;
		this->ui.equationList->addItem(QString::fromStdString(u));
	}
}

void ecuatii::computeValues()
{
	QListWidgetItem *it = this->ui.equationList->currentItem();
	std::string str = ((*it).text()).toStdString();
	std::size_t a = str.find_first_of("*");
	std::string astr;
	astr.assign(str,0, a);
	std::size_t b = str.find_first_of("*", a+1);
	std::string bstr;
	bstr.assign(str, a+7, b-a-7);

	std::size_t c = str.find_first_of("*", b + 1);
	std::string cstr;
	cstr.assign(str, b + 5, c - b - 5);

	double ad = stod(astr);
	double bd = stod(bstr);
	double cd = stod(cstr);

	double delta = bd*bd - 4 * ad*cd;
	
	std::string sol1 = "";
	std::string sol2 = "";

	if (delta < 0)
	{
		delta = -delta;
		delta = sqrt(delta);
		ad = 2 * ad;
		sol1 += "( -" + bstr + "+ i* " + std::to_string(delta) + " )/" + "2 * " + std::to_string(ad);

		sol2 += "( -" + bstr + "- i* " + std::to_string(delta) + " )/" + "2 * " + std::to_string(ad);
	}
	else {
		delta = sqrt(delta);
		double s1, s2;
		s1 = (-bd + delta) / (2 * ad);
		s2 = (-bd - delta) / (2 * ad);
		sol1 = std::to_string(s1);
		sol2 = std::to_string(s2);
	}
	this->ui.labelSol1->setText(QString::fromStdString(sol1));
	this->ui.labelSol2->setText(QString::fromStdString(sol2));

}

void ecuatii::editFct()
{
	QListWidgetItem *it = this->ui.equationList->currentItem();
	std::string str = ((*it).text()).toStdString();
	std::size_t a = str.find_first_of("*");
	std::string astr;
	astr.assign(str, 0, a);
	std::size_t b = str.find_first_of("*", a + 1);
	std::string bstr;
	bstr.assign(str, a + 7, b - a - 7);

	std::size_t c = str.find_first_of("*", b + 1);
	std::string cstr;
	cstr.assign(str, b + 5, c - b - 5);
	
	this->ui.alineEdit->setText(QString::fromStdString(astr));

	this->ui.blineEdit->setText(QString::fromStdString(bstr));

	this->ui.clineEdit->setText(QString::fromStdString(cstr));


	double ad = stod(astr);
	double bd = stod(bstr);
	double cd = stod(cstr);
}

void ecuatii::edita()
{
	//double ad = this->ui.alineEdit.
}

void ecuatii::editb()
{
}

void ecuatii::editc()
{
}
