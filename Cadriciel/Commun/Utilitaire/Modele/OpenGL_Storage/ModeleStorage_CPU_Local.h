///////////////////////////////////////////////////////////////////////////////
/// @file ModeleStorage_CPU_Local.h
/// @author Martin Paradis
/// @date 2014-08-16
/// @version 1.0
///
/// @addtogroup modele Modele
/// @{
///////////////////////////////////////////////////////////////////////////////

#ifndef __MODELESTORAGE_CPU_LOCAL_H__
#define __MODELESTORAGE_CPU_LOCAL_H__

#include "ModeleStorageRendu.h"

namespace modele{
	class  Modele3D;
	class  Noeud;
	struct Materiau;

	namespace opengl_storage{

		///////////////////////////////////////////////////////////////////////////
		/// @class CPU_Local
		/// @brief Classe permettant le dessin d'un mod�le 3D sans aucun storage
		/// de donn�es ou de commandes sur la carte graphique.
		///
		/// @note Pr�condition : prends pour acquis que le pointeur vers le mod�le
		/// 3D reste valide durant toute la dur�e de vie du storage.
		///
		/// @author Martin Paradis
		/// @date 2014-08-16
		///////////////////////////////////////////////////////////////////////////
		class CPU_Local : public ModeleStorageRendu{
		public:
			CPU_Local() = default;
			/// Constructeur avec un mod�le 3D
			CPU_Local(Modele3D const* modele);
			
			/// Destructeur
			virtual ~CPU_Local() = default;

			/// Permet de charger les donn�es/commandes sur la carte graphique
			virtual void storageCharger() override;
			/// Permet d'effectuer le dessin du mod�le 3D
			virtual void dessiner() const override;
			/// Permet de rel�cher les donn�es/commandes sur la crate graphique
			virtual void storageRelacher() override;

		private:
			/// Mod�le � dessiner
			modele::Modele3D const* modele_{ nullptr };

			/// Dessin r�cursif du mod�le 3D
			void dessiner(modele::Noeud const& noeud) const;
			/// Assigne le mat�riau pour une face quelconque
			void appliquerMateriau(modele::Materiau const& materiau) const;
		};
	}
}

#endif /// __MODELESTORAGE_CPU_LOCAL_H__

///////////////////////////////////////////////////////////////////////////////
/// @}
///////////////////////////////////////////////////////////////////////////////