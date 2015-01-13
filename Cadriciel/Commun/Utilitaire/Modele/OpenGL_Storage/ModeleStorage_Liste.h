///////////////////////////////////////////////////////////////////////////////
/// @file ModeleStorage_Liste.h
/// @author Martin Paradis
/// @date 2014-08-16
/// @version 1.0
///
/// @addtogroup modele Modele
/// @{
///////////////////////////////////////////////////////////////////////////////

#ifndef __MODELESTORAGE_LISTE_H__
#define __MODELESTORAGE_LISTE_H__

#include "ModeleStorageRendu.h"

namespace modele{
	class Modele3D;

	namespace opengl_storage{
		///////////////////////////////////////////////////////////////////////////
		/// @class OpenGL_Liste
		/// @brief Classe permettant de d�/charger des commandes OpenGL sur la carte
		/// graphique et d'en effectuer le dessin
		///
		/// @note Pr�condition : prends pour acquis que le pointeur vers le mod�le
		/// 3D est valide durant le chargement du storage.
		///
		/// @author Martin Paradis
		/// @date 2014-08-16
		///////////////////////////////////////////////////////////////////////////
		class OpenGL_Liste : public ModeleStorageRendu {
		public:
			OpenGL_Liste() = default;
			/// Constructeur � partir d'un mod�le 3D
			OpenGL_Liste(modele::Modele3D const* modele);
			/// Destructeur
			virtual ~OpenGL_Liste();

			/// Permet de charger les donn�es/commandes sur la carte graphique
			virtual void storageCharger() override;
			/// Permet d'effectuer le dessin du mod�le 3D
			virtual void dessiner() const override;
			/// Permet de rel�cher les donn�es/commandes sur la crate graphique
			virtual void storageRelacher() override;

		private:
			/// Permet de v�rifier si l'identifiant est valide
			inline bool identifiantEstValide() const;

			static const unsigned int LISTE_INVALIDE{ 0 };

			/// Mod�le � dessiner
			modele::Modele3D const* modele_{ nullptr };
			/// Identifiant de list OpenGL
			unsigned int handle_{ LISTE_INVALIDE };
			
		};

		////////////////////////////////////////////////////////////////////////
		///
		/// @fn inline bool OpenGL_Liste::identifiantEstValide() const
		///
		/// Permet de v�rifier si l'identifiant est valide
		///
		/// @return Vrai si l'identifiant est valide, faux sinon.
		///
		////////////////////////////////////////////////////////////////////////
		inline bool OpenGL_Liste::identifiantEstValide() const
		{
			return handle_ != LISTE_INVALIDE;
		}
	}
}

#endif /// __MODELESTORAGE_LISTE_H__

///////////////////////////////////////////////////////////////////////////////
/// @}
///////////////////////////////////////////////////////////////////////////////