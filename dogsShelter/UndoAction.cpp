#include "UndoAction.h"

UndoAction::~UndoAction()
{
}

UndoAdd::UndoAdd(Repository * _r, Dog _du, Dog _dr): repo{_r}, dogUndo{_du}, dogRedo(_dr)
{
}

void UndoAdd::executeUndo()
{
	this->repo->removeDog(this->dogUndo);
}

void UndoAdd::executeRedo()
{
	this->repo->addDog(this->dogRedo);
}

UndoRemove::UndoRemove(Repository* _r, Dog _du, Dog _dr): repo{_r}, dogUndo{_du}, dogRedo{_dr}
{
}

void UndoRemove::executeUndo()
{
	this->repo->addDog(this->dogUndo);
}

void UndoRemove::executeRedo()
{
	this->repo->removeDog(this->dogRedo);

}

UndoUpdate::UndoUpdate(Repository* _r, Dog _du, Dog _dr): repo{_r}, dogUndo{_du}, dogRedo{_dr}
{
}

void UndoUpdate::executeUndo()
{
	this->repo->updateDog(this->dogUndo);
}

void UndoUpdate::executeRedo()
{
	this->repo->updateDog(this->dogRedo);
}
