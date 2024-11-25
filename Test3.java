import java.util.Arrays;
import java.util.Scanner;

public class Test3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        GamePlayEngine engine = new GamePlayEngine(sc);

        engine.printGameResult();
    }
}

class GamePlayEngine {
    static final int CHAR_ARG_LENGTH = 4;

    Game currentGame;

    int[] monsterMoveQueue;
    int monsterMoveQueueIdx = 0;

    public GamePlayEngine(Scanner sc) throws IllegalArgumentException {
        String[] playerInfo = sc.nextLine().split(" ");
        String[] monsterInfo = sc.nextLine().split(" ");
        String[] monsterMovesInfo = sc.nextLine().split(" ");

        Character player = initializeCharacter(playerInfo);
        Character[] monsters = initializeCharacters(monsterInfo);
        monsterMoveQueue = initializeMonsterMoves(monsterMovesInfo);

        currentGame = new Game(player, monsters);

        doGameLoop(sc);
    }

    private int[] initializeMonsterMoves(String[] monsterMovesInfo) {

        int queueSize = monsterMovesInfo.length;
        int[] newMonsterMoveQueue = new int[queueSize];

        for (int i = 0; i < queueSize; ++i) {
            newMonsterMoveQueue[i] = Integer.parseInt(monsterMovesInfo[i]);
        }

        return newMonsterMoveQueue;
    }

    private void popMonsterMoveQueue(int monsterId) {
        if (monsterId == -1)
            return;

        Character monster = currentGame.getMonster(monsterId);
        Character player = currentGame.getPlayer();

        int damage = monster.attack(player);
        logAttack(monster, player, monster.getWeapon(), damage);
    }

    private void logAttack(Character attacker, Character target, Weapon weapon, int damage) {
    	System.out.printf("[SYSTEM] %s attacked %s with %s, %d of damage has been applied%n",attacker.getName(),target.getName(),weapon.getName(),damage);
    	  if (!target.isAlive())
              System.out.printf("[SYSTEM] %s is now dead!%n", target.getName());
        // 여기를 채우세요
    }

    private void doGameLoop(Scanner sc) {
        boolean isGameContinue = true;

        while (isGameContinue) {
            isGameContinue = sc.hasNextLine();

            if (isGameContinue) {
                String[] controls = sc.nextLine().split(" ");

                if (controls.length == 0) {
                    continue;
                }

                switch (controls[0]) {
                    case "attack":
                        int target = Integer.parseInt(controls[1]);
                        Character monster = currentGame.getMonster(target);
                        int damage = currentGame.getPlayer().attack(monster);
                        Weapon weapon = currentGame.getPlayer().getWeapon();

                        logAttack(currentGame.getPlayer(), monster, weapon, damage);

                        break;
                }
            }

            isGameContinue = isGameContinue || monsterMoveQueueIdx < monsterMoveQueue.length;

            if (isGameContinue && monsterMoveQueueIdx < monsterMoveQueue.length)
                popMonsterMoveQueue(monsterMoveQueue[monsterMoveQueueIdx++]);
        }
    }

    private Character[] initializeCharacters(String[] serializedCharacterInfo) {
        if (serializedCharacterInfo == null || serializedCharacterInfo.length == 0)
            return null;

        if (serializedCharacterInfo.length % CHAR_ARG_LENGTH > 0)
            throw new IllegalArgumentException("Malformed length info");

        int charCount = serializedCharacterInfo.length / CHAR_ARG_LENGTH;
        Character[] characters = new Character[charCount];

        for (int i = 0; i < charCount; ++i) {
            String[] subArray = Arrays.copyOfRange(serializedCharacterInfo, CHAR_ARG_LENGTH * i, CHAR_ARG_LENGTH * i + CHAR_ARG_LENGTH);
            characters[i] = initializeCharacter(subArray);
        }

        return characters;
    }

    private Character initializeCharacter(String[] characterInfo) {
        if (characterInfo.length != CHAR_ARG_LENGTH)
            throw new IllegalArgumentException("Malformed length info");

        String name = characterInfo[0];

        int hp = Integer.parseInt(characterInfo[1]);

        Weapon weapon = null;
        String wName = characterInfo[2];

        if (!"-1".equals(wName)) {
            int wDamage = Integer.parseInt(characterInfo[3]);
            weapon = new Weapon(wName, wDamage);
        }

        return new Character(name, hp, weapon);
    }

    public void printCharacterState(String type, Character character) {
    	System.out.printf("[%s] Name: %s, HP: %d%n",type,character.getName(),character.getHp());
    	System.out.printf("-> with weapon %s (damage %d)%n",character.getWeapon().getName(),character.getWeapon().getDamage());
    	
        // 여기를 채우세요
    }

    public void printGameResult() {
    	 printCharacterState("Player", currentGame.getPlayer());
         for(int i=0; i< currentGame.getMonsterCount(); i++){
              printCharacterState("Monster", currentGame.getMonster(i));
          }


        // 여기를 채우세요
    }
}

class Game {
    private Character player;
    private Character[] monsters;

    public Game(Character player, Character[] monsters) {
        this.player = player;
        this.monsters = monsters;
    }

    public void setPlayer(Character player) {
        this.player = player;
    }

    public Character getMonster(int i) {
        return monsters[i];
    }

    public int getMonsterCount() {
        return monsters.length;
    }

    public Character getPlayer() {
        return player;
    }
}

class Size {
    public int width;
    public int height;

    public boolean equals(Size size) {
        if (size == null) return false;
        else if (this == size) return true;

        return size.width == this.width && size.height == this.height;
    }
}

class Weapon {
    private final String name;
    private final int damage;

    public Weapon(String name, int damage) {
        this.name = name;
        this.damage = damage;
    }

    public String getName() {
        return name;
    }

    public int getDamage() {
        return damage;
    }
}

class Character {
    private String name;
    private int hp;

    private Weapon weapon;

    public Character(String name, int hp, Weapon weapon) {
        this.name = name;
        this.hp = hp;
        this.weapon = weapon;
    }

    public int getHp() {
        return hp;
    }

    public int applyDamage(int damage) {
    	  if(hp < damage){
              damage = hp;
          }
          hp -= damage;
          return damage;
        // 여기를 채우세요
    }

    public String getName() {
        return this.name;
    }

    public int attack(Character target) {
    	 return target.applyDamage(weapon.getDamage());
        // 여기를 채우세요
    }

    public boolean isAlive() {
        return hp > 0;
    }

    public Weapon getWeapon() {
        return weapon;
    }
}
