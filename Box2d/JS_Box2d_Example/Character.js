class Character
{
  constructor(X,Y,width,height,type,tag)
  {
    this.shape=this.createPlayer(X,Y,width,height,type,tag);
    this.shape.SetFixedRotation(true);

    this.numFootContacts=0;
    this.width=width;
    this.height=height;
    this.animateCount=0;
    this.sx=0;
    this.sy=0;
    this.swidth=32;
    this.sheight=32;
    this.img=new Image();
    this.img.src="playerWalk.png"
    this.Flip=false;

  }

  createPlayer(X,Y,width,height,type,tag)
  {
    var bodyDef = new b2BodyDef;
    bodyDef.type = type;
    bodyDef.position.x = X/2/scale;
    bodyDef.position.y = Y/scale;

    // A fixture is used to attach a shape to a body for collision detection.
    // A fixture definition is used to create a fixture
    var fixtureDef = new b2FixtureDef;
    fixtureDef.density = 1.0;
    fixtureDef.friction = 0.5;
    fixtureDef.restitution = 0.2;

    fixtureDef.shape = new b2PolygonShape;
    fixtureDef.shape.SetAsBox(width/scale,height/scale); //640 pixels wide and 20 pixels tall

    var body = world.CreateBody(bodyDef);
    var fixture = body.CreateFixture(fixtureDef);

    fixtureDef.isSensor = true;
    var footSensorFixture =body.CreateFixture(fixtureDef);
    footSensorFixture.SetUserData( tag );

    return body;
  }

  movePlayer()
  {
    var vel = this.shape.GetLinearVelocity();
    vel.x = 5*movementDirection;
    this.shape.SetLinearVelocity(vel);
  }
  jump()
  {
    var vel = player.shape.GetLinearVelocity();
    vel.y = -7;
    player.shape.SetLinearVelocity( vel );
  }

  Animate()
  {
    this.animateCount++;
    if(this.animateCount>=2*(1000/17))
    {
      if(this.sx+32<=192)
        this.sx+=32;
      else
        this.sx=0;
      this.animateCount=0;
    }
  }


}
