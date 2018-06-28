// Declare all the commonly used objects as variables for convenience
var b2Vec2 = Box2D.Common.Math.b2Vec2;
var b2BodyDef = Box2D.Dynamics.b2BodyDef;
var b2Body = Box2D.Dynamics.b2Body;
var b2FixtureDef = Box2D.Dynamics.b2FixtureDef;
var b2Fixture = Box2D.Dynamics.b2Fixture;
var b2World = Box2D.Dynamics.b2World;
var b2PolygonShape = Box2D.Collision.Shapes.b2PolygonShape;
var b2CircleShape = Box2D.Collision.Shapes.b2CircleShape;
var b2DebugDraw = Box2D.Dynamics.b2DebugDraw;
var b2RevoluteJointDef = Box2D.Dynamics.Joints.b2RevoluteJointDef;
var b2Listener = Box2D.Dynamics.b2ContactListener;


var player=null;
var isMoving=false;
var movementDirection=1;
var isJumping=false;

var listener = new b2Listener;
var world;
var scale = 30; //30 pixels on our canvas correspond to 1 meter in the box2d world
function init(){
	// Setup the box2d World that will do most of they physics calculation
	var gravity = new b2Vec2(0,9.8); //declare gravity as 9.8 m/s^2 downwards
	var allowSleep = false; //Allow objects that are at rest to fall asleep and be excluded from calculations
	world = new b2World(gravity,allowSleep);

	player=new Character(200,200,10,10,b2Body.b2_dynamicBody,2);

	createBody(640/2,480,640,50,b2Body.b2_staticBody,0,1);
	createBody(10,480/2,20,480,b2Body.b2_staticBody,0,1);
	createBody(1280,480/2,20,480,b2Body.b2_staticBody,0,1);

	//plataformas
	createBody(1000,400,50,10,b2Body.b2_staticBody,0,1);
	createBody(700,350,50,10,b2Body.b2_staticBody,0,1);
	createBody(200,300,50,10,b2Body.b2_staticBody,0,1);
	createBody(700,250,50,10,b2Body.b2_staticBody,0,1);
	createBody(635,200,15,10,b2Body.b2_staticBody,0,1);
	createBody(765,200,15,10,b2Body.b2_staticBody,0,1);
	createBody(200,200,50,10,b2Body.b2_staticBody,0,1);
	createBody(80,175,15,15,b2Body.b2_staticBody,0,1);
	createBody(135,150,15,10,b2Body.b2_staticBody,0,1);
	createBody(250,100,50,10,b2Body.b2_staticBody,0,1);
	createBody(700,50,50,10,b2Body.b2_staticBody,0,3);



	world.SetContactListener(listener);
	GameCanvas=document.getElementById('GameCanvas');
	ctx=GameCanvas.getContext("2d");
	setupDebugDraw();
	animate();
}

function createBody(X,Y,width,height,type,friction,tag){
	//A body definition holds all the data needed to construct a rigid body.
	var bodyDef = new b2BodyDef;
	bodyDef.type = type;
	bodyDef.position.x = X/2/scale;
	bodyDef.position.y = Y/scale;

	// A fixture is used to attach a shape to a body for collision detection.
	// A fixture definition is used to create a fixture
	var fixtureDef = new b2FixtureDef;
	fixtureDef.density = 1.0;
	fixtureDef.friction = friction;
	fixtureDef.restitution = 0.2;

	fixtureDef.shape = new b2PolygonShape;
	fixtureDef.shape.SetAsBox(width/scale,height/scale);

	var body = world.CreateBody(bodyDef);
	var fixture = body.CreateFixture(fixtureDef);
	fixture.SetUserData( tag );

	return body;
}



var context;
function setupDebugDraw(){
	context = document.getElementById('DebugCanvas').getContext('2d');

	var debugDraw = new b2DebugDraw();

	// Use this canvas context for drawing the debugging screen
	debugDraw.SetSprite(context);
	// Set the scale
	debugDraw.SetDrawScale(scale);
	// Fill boxes with an alpha transparency of 0.3
	debugDraw.SetFillAlpha(1);
	// Draw lines with a thickness of 1
	debugDraw.SetLineThickness(1.0);
	// Display all shapes and joints
	debugDraw.SetFlags(b2DebugDraw.e_shapeBit | b2DebugDraw.e_jointBit);

	// Start using debug draw in our world
	world.SetDebugDraw(debugDraw);
}

var timeStep = 1/60;

//As per the Box2d manual, the suggested iteration count for Box2D is 8 for velocity and 3 for position.
var velocityIterations = 8;
var positionIterations = 3;

function animate(){
	world.Step(timeStep,velocityIterations,positionIterations);
	world.ClearForces();
	if(isMoving)
		this.player.Animate();
	if(!this.moving)
		this.player.sx=0;
	world.DrawDebugData();
	if(isMoving && player.shape.GetLinearVelocity().x<10)
		player.movePlayer();
		for (b = world.GetBodyList() ; b; b = b.GetNext()) {

						var pos = b.GetPosition();
						context.save();
						context.translate(pos.x * scale, pos.y * scale);
						context.rotate(b.GetAngle());
						if (b.GetType() == b2Body.b2_dynamicBody)
						{
							setCoords(pos.x,pos.y);
							Update();
						}

						context.restore();
		}

	setTimeout(animate, timeStep);
}

function paintPlayer()
{
	ctx.save();
	if(this.player.Flip)
	{
		ctx.scale(-1,1);
		ctx.drawImage(this.player.img,this.player.sx,this.player.sy,this.player.swidth,this.player.sheight,-this.player.X*scale,this.player.Y*scale,10,12);
	}
	else {
		ctx.drawImage(this.player.img,this.player.sx,this.player.sy,this.player.swidth,this.player.sheight,this.player.X*scale,this.player.Y*scale,10,12);
	}
	ctx.restore();

}

document.addEventListener('keydown',function(event){
	KeyDownEvent(event);
});
document.addEventListener('keyup',function(event){
	KeyUpEvent(event);
});



function KeyDownEvent(event)
{
	if(event.keyCode==37  ) //izquierda
	{
		isMoving=true;
		player.Flip=true;
		movementDirection=-1;
	}

	if(event.keyCode==39  ) //derecha
	{
		isMoving=true;
		player.Flip=false;
		movementDirection=1;
	}

	if(event.keyCode==38) //Arriba
	{
		if(player.numFootContacts>0)
		{
			player.jump();
		}
	}
}

function KeyUpEvent(event)
{
	if(event.keyCode==37  ) //izquierda
	{
		isMoving=false;
		var vel = player.shape.GetLinearVelocity();
		vel.x = 0;
		player.shape.SetLinearVelocity(vel);
	}

	if(event.keyCode==39  ) //derecha
	{
		isMoving=false;
		var vel = player.shape.GetLinearVelocity();
		vel.x = 0;
		player.shape.SetLinearVelocity(vel);
	}
}


listener.BeginContact = function(contact)
{
	var fixtureUserData = contact.GetFixtureA().GetUserData();
	if ( fixtureUserData == 2)
			player.numFootContacts++;
	//check if fixture B was the foot sensor
	fixtureUserData = contact.GetFixtureB().GetUserData();
	if (fixtureUserData == 2 )
			player.numFootContacts++;
	}

listener.EndContact = function(contact)
{
	//check if fixture A was the foot sensor
	var fixtureUserData = contact.GetFixtureA().GetUserData();
	if (fixtureUserData == 2 )
			player.numFootContacts--;
	if(fixtureUserData == 3 )
		location.reload();
	//check if fixture B was the foot sensor*/
	fixtureUserData = contact.GetFixtureB().GetUserData();
	if (fixtureUserData == 2 )
			player.numFootContacts--;
	if(fixtureUserData == 3 )
		location.reload();


	}

listener.PostSolve = function(contact, impulse) {}

listener.PreSolve = function(contact, oldManifold) {}
