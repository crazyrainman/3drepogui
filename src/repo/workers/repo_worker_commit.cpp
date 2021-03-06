/**
*  Copyright (C) 2014 3D Repo Ltd
*
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the GNU Affero General Public License as
*  published by the Free Software Foundation, either version 3 of the
*  License, or (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU Affero General Public License for more details.
*
*  You should have received a copy of the GNU Affero General Public License
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "repo_worker_commit.h"
#include <list>
#include <string>
#include <cctype>

using namespace repo::worker;

CommitWorker::CommitWorker(
	repo::RepoController *controller, 
	const repo::RepoController::RepoToken *token,
	repo::core::model::RepoScene *scene)
	: RepoAbstractWorker(),
	controller(controller),
	token(token),
	scene(scene)
{}

CommitWorker::~CommitWorker() {}

void CommitWorker::run()
{
	repoLog(tr("Commiting scene to the database, please wait...").toStdString());
	
	emit progress(0, 0);
	controller->commitScene(token, scene);

	//--------------------------------------------------------------------------
	// End
	emit progress(1, 1);
	//--------------------------------------------------------------------------
	// Done
	emit RepoAbstractWorker::finished();
}


