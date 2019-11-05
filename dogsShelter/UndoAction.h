#pragma once
#include "Repository.h"
#include "Dog.h"

class UndoAction
{
public:
	
	virtual void executeUndo() = 0;
	virtual void executeRedo() = 0;
	virtual ~UndoAction();
};



class UndoAdd : public UndoAction
{
private:
	Repository* repo;
	Dog dogUndo;
	Dog dogRedo;
public:
	UndoAdd(Repository* _r, Dog _du, Dog _dr);
	void executeUndo() override;
	void executeRedo() override;
};


class UndoRemove : public UndoAction
{
private:
	Repository* repo;
	Dog dogUndo;
	Dog dogRedo;
public:
	UndoRemove(Repository* _r, Dog _du, Dog _dr);
	void executeUndo() override;
	void executeRedo() override;
};

class UndoUpdate : public UndoAction
{
private:
	Repository* repo;
	Dog dogUndo;
	Dog dogRedo;
public:
	UndoUpdate(Repository* _r, Dog _du, Dog _dr);
	void executeUndo() override;
	void executeRedo() override;
};

