/*
  RTQL8, Copyright (c) 2011 Georgia Tech Graphics Lab
  All rights reserved.

  Author	Sehoon Ha
  Date		06/12/2011
*/

#ifndef MODEL3D_SKELETON_H
#define MODEL3D_SKELETON_H

#include <vector>
#include <Eigen/Dense>

namespace Renderer {
    class OpenGLRenderInterface;
} // namespace Renderer

namespace model3d {

    class Transformation;
    class Marker;
    class Joint;
    class BodyNode;
    class Dof;

    class Skeleton {
    public:
        Eigen::VectorXd mCurrState; 
        BodyNode* mRoot;
        int nDofs;
        int nNodes;
        int nHandles;

        Skeleton();
        virtual ~Skeleton();
	
        void addHandle(Marker *h);
        void addNode(BodyNode *b);
        void addJoint(Joint *_j);
        void addDof(Dof *d);
        void addTransform(Transformation *t);
	
        // init the model after parsing
        void initSkel();
	
        // inline access functions
        int getNumDofs() { return mDofs.size(); }
        int getNumNodes() { return mNodes.size(); }
        int getNumHandles() { return mHandles.size(); }
        Dof* getDof(int i) { return mDofs[i]; }
        BodyNode* getNode(int i) { return mNodes[i]; }
        BodyNode* getNode(const char* const name);
        int getNodeIndex(const char* const name);
        Marker* getHandle(int i) { return mHandles[i]; }
        double getMass() { return mMass; }

        void setState(const Eigen::VectorXd&);
        void setState(const std::vector<double>&);

        void draw(Renderer::OpenGLRenderInterface* RI, const Eigen::Vector4d& _color, bool _default = true) ;
        void drawHandles(Renderer::OpenGLRenderInterface* RI, const Eigen::Vector4d& _color, bool _default = true );
	
        void setPose(const Eigen::VectorXd& _pose);
        void setPose(const std::vector<double>& _pose);
        void getPose(Eigen::VectorXd& _pose);
        void getPose(std::vector<double>& _pose);

    protected:
        std::vector<Marker*> mHandles;
        std::vector<Dof*> mDofs;
        std::vector<Transformation*> mTransforms;
        std::vector<BodyNode*> mNodes;
        std::vector<Joint*> mJoints;

        double mMass;
    };

} // namespace model3d

#endif // #ifndef MODEL3D_SKELETON_H
